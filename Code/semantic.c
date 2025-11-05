#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lab2/Symbol/Symbol.h"
#include "lab2/Type/Type.h"
#include "semantic.h"

extern int error_code;

// 错误输出
void printError(int type, int line, const char *msg) {
    printf("Error type %d at Line %d: %s.\n", type, line, msg);
}

// ==================== 主入口 ====================
void semanticAnalysis(Node *root) {
    if (!root)
        return;
    enterScope();
    traverseProgram(root);
    exitScope();
}

// ==================== Program/ExtDefList/ExtDef ====================
void traverseProgram(Node *node) {
    if (!node || node->child_count == 0)
        return;
    traverseExtDefList(node->children[0]);
}

void traverseExtDefList(Node *node) {
    if (!node || node->child_count == 0)
        return;
    traverseExtDef(node->children[0]);
    if (node->child_count == 2)
        traverseExtDefList(node->children[1]);
}

void traverseExtDef(Node *node) {
    if (!node || node->child_count == 0)
        return;
    Node *specifier = node->children[0];
    Type *baseType = getType(specifier);

    // 结构体定义（仅 Specifier 无变量实例）
    if (node->child_count == 2 && specifier->child_count > 0 && strcmp(specifier->children[0]->type, "StructSpecifier") == 0) {
        handleStructSpecifier(specifier->children[0]);
    }
    // 全局变量声明（Specifier + ExtDecList + SEMI）
    else if (node->child_count == 3 && strcmp(node->children[1]->type, "ExtDecList") == 0) {
        // 首先处理 specifier 中可能的 struct 定义
        if (specifier->child_count > 0 && strcmp(specifier->children[0]->type, "StructSpecifier") == 0) {
            handleStructSpecifier(specifier->children[0]);
        }
        // 然后处理变量声明
        traverseExtDecList(node->children[1], baseType);
    }
    // 函数定义
    else if (node->child_count == 3 && strcmp(node->children[1]->type, "FunDec") == 0) {
        handleFuncDef(node->children[1], baseType, node->children[2]);
    }
}

// ==================== ExtDecList/Def/DecList ====================
void traverseExtDecList(Node *node, Type *baseType) {
    if (!node || node->child_count == 0)
        return;
    Node *varDec = node->children[0];
    // 递归查找 ID 节点，兼容多维数组 VarDec 嵌套结构
    Node *idNode = varDec;
    while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) {
        idNode = idNode->children[0];
    }
    if (!idNode || strcmp(idNode->type, "ID") != 0) {
        return;
    }
    char *varName = idNode->value;
    int line = idNode->lineNo;

    // 处理数组类型
    Type *finalType = baseType;
    Node *cur = varDec;
    while (cur->child_count == 4) {
        Type *arr = malloc(sizeof(Type));
        arr->kind = ARRAY_TYPE;
        arr->base = finalType;
        arr->arrayDim = 1;
        arr->arraySizes = malloc(sizeof(int));
        arr->arraySizes[0] = atoi(cur->children[2]->value);
        arr->structType = NULL;
        finalType = arr;
        cur = cur->children[0];
    }

    // 检查变量名是否与结构体名重复
    Symbol *existing = findSymbol(varName);
    if (existing && existing->kind == STRUCT_KIND) {
        printError(3, line, "Variable name conflicts with struct name");
    } else {
        Symbol *varSym = createVariableSymbol(varName, finalType, line);
        insertSymbol(varSym);
        if (error_code != 0)
            printError(error_code, line, "Variable insert error");
    }

    if (node->child_count == 3)
        traverseExtDecList(node->children[2], baseType);
}

void traverseDefList(Node *node) {
    if (!node || node->child_count == 0)
        return;
    traverseDef(node->children[0]);
    if (node->child_count == 2)
        traverseDefList(node->children[1]);
}

void traverseDef(Node *node) {
    if (!node || node->child_count < 3)
        return;
    Type *baseType = getType(node->children[0]);
    // 在处理 DecList 之前，先处理可能的 struct 定义
    Node *specifier = node->children[0];
    if (specifier->child_count > 0 && strcmp(specifier->children[0]->type, "StructSpecifier") == 0) {
        handleStructSpecifier(specifier->children[0]);
    }
    traverseDecList(node->children[1], baseType);
}

void traverseDecList(Node *node, Type *baseType) {
    if (!node || node->child_count == 0)
        return;
    Node *dec = node->children[0];
    Node *varDec = dec->children[0];

    // 修正：递归查找ID节点，处理数组变量的嵌套结构
    Node *idNode = varDec;
    while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) {
        idNode = idNode->children[0];
    }

    if (strcmp(idNode->type, "ID") != 0) {
        return;
    }

    char *varName = idNode->value;
    int line = idNode->lineNo;

    // 处理数组类型
    Type *finalType = baseType;
    Node *cur = varDec;
    while (cur->child_count == 4) {
        Type *arr = malloc(sizeof(Type));
        arr->kind = ARRAY_TYPE;
        arr->base = finalType;
        arr->arrayDim = 1;
        arr->arraySizes = malloc(sizeof(int));
        arr->arraySizes[0] = atoi(cur->children[2]->value);
        arr->structType = NULL;
        finalType = arr;
        cur = cur->children[0];
    }

    // 检查变量名是否与结构体名重复
    Symbol *existing = findSymbol(varName);
    if (existing && existing->kind == STRUCT_KIND) {
        printError(3, line, "Variable name conflicts with struct name");
    } else {
        Symbol *varSym = createVariableSymbol(varName, finalType, line);
        insertSymbol(varSym);
        if (error_code != 0) {
            printError(error_code, line, "Variable insert error");
        }
    }

    // 检查初始化类型
    if (dec->child_count == 3) {
        Type *expType = checkExp(dec->children[2]);
        if (!TypeEqual(finalType, expType)) {
            printError(5, line, "Type mismatched for assignment");
        }
    }
    if (node->child_count == 3)
        traverseDecList(node->children[2], baseType);
}

// ==================== 结构体处理 ====================
Type *handleStructSpecifier(Node *node) {
    if (!node)
        return NULL;
    // STRUCT OptTag LC DefList RC
    if (node->child_count == 5) {
        Node *optTag = node->children[1];
        Node *defList = node->children[3];
        char *structName = NULL;
        if (optTag && optTag->child_count == 1)
            structName = optTag->children[0]->value;

        // 收集成员
        int memberCount = 0;
        Node *curDefList = defList;
        while (curDefList && curDefList->child_count > 0) {
            Node *def = curDefList->children[0];
            Node *decList = def->children[1];
            Node *curDecList = decList;
            while (curDecList && curDecList->child_count > 0) {
                memberCount++;
                if (curDecList->child_count == 3)
                    curDecList = curDecList->children[2];
                else
                    break;
            }
            if (curDefList->child_count == 2)
                curDefList = curDefList->children[1];
            else
                break;
        }
        Symbol **members = memberCount > 0 ? malloc(sizeof(Symbol *) * memberCount) : NULL;
        int idx = 0;
        curDefList = defList;
        while (curDefList && curDefList->child_count > 0) {
            Node *def = curDefList->children[0];
            // 字段的基本类型：当字段的 Specifier 是 StructSpecifier（可能包含命名的嵌套结构体定义）时，
            // 走 handleStructSpecifier，确保执行结构体名重定义检查（Error 16）并进行必要的插入；
            // 否则走常规 getType。
            Type *baseType = NULL;
            Node *fieldSpecifier = def->children[0]; // 这是一个 Specifier
            if (fieldSpecifier && fieldSpecifier->child_count > 0 &&
                strcmp(fieldSpecifier->children[0]->type, "StructSpecifier") == 0) {
                baseType = handleStructSpecifier(fieldSpecifier->children[0]);
            } else {
                baseType = getType(fieldSpecifier);
            }
            Node *decList = def->children[1];
            Node *curDecList = decList;
            while (curDecList && curDecList->child_count > 0) {
                Node *dec = curDecList->children[0];
                Node *varDec = dec->children[0];
                // 递归查找 ID 节点，兼容数组成员声明
                Node *idNode = varDec;
                while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) {
                    idNode = idNode->children[0];
                }
                if (!idNode || strcmp(idNode->type, "ID") != 0) {
                    // 无法找到字段名，跳过
                    if (curDecList->child_count == 3)
                        curDecList = curDecList->children[2];
                    else
                        break;
                    continue;
                }
                char *fieldName = idNode->value;
                int line = idNode->lineNo;
                // 域名重复
                bool duplicate = false;
                for (int j = 0; j < idx; j++) {
                    if (strcmp(members[j]->name, fieldName) == 0) {
                        printError(15, line, "Duplicate field name in struct");
                        duplicate = true;
                        break;
                    }
                }
                if (duplicate) {
                    // 跳过重复的成员，不添加到members数组中
                    if (curDecList->child_count == 3)
                        curDecList = curDecList->children[2];
                    else
                        break;
                    continue; // 跳过后续处理
                }
                // 域初始化
                if (dec->child_count == 3)
                    printError(15, line, "Struct field initialized");
                // 处理数组
                Type *finalType = baseType;
                Node *curVar = varDec;
                while (curVar->child_count == 4) {
                    Type *arr = malloc(sizeof(Type));
                    arr->kind = ARRAY_TYPE;
                    arr->base = finalType;
                    arr->arrayDim = 1;
                    arr->arraySizes = malloc(sizeof(int));
                    arr->arraySizes[0] = atoi(curVar->children[2]->value);
                    arr->structType = NULL;
                    finalType = arr;
                    curVar = curVar->children[0];
                }
                members[idx++] = createVariableSymbol(fieldName, finalType, line);
                if (curDecList->child_count == 3)
                    curDecList = curDecList->children[2];
                else
                    break;
            }
            if (curDefList->child_count == 2)
                curDefList = curDefList->children[1];
            else
                break;
        }
        // 使用实际添加的成员数量 idx，而不是初始的 memberCount
        Symbol *structSym = createStructSymbol(structName ? structName : "", node->lineNo, idx, members);
        // 添加调试代码
        // printf("DEBUG: createStructSymbol returned %p, error_code=%d\n", (void*)structSym, error_code);
        if (structSym == NULL) {
            // printf("DEBUG: createStructSymbol failed, likely due to duplicate members\n");
            //  如果创建结构体符号失败（可能是因为重复成员），直接返回NULL
            return NULL;
        }
        if (structName) {
            Symbol *exist = findSymbol(structName);
            // 添加调试代码
            // printf("DEBUG: Checking struct redefinition for '%s' at line %d\n", structName, node->lineNo);
            if (exist) {
                // printf("DEBUG: Struct '%s' already exists, kind=%d\n", structName, exist->kind);
                printError(16, node->lineNo, "Struct name redefined");
            } else {
                // printf("DEBUG: Inserting new struct '%s'\n", structName);
                insertSymbol(structSym);
            }
        }
        Type *retType = malloc(sizeof(Type));
        retType->kind = STRUCTURE_TYPE;
        retType->structType = structSym;
        retType->base = NULL;
        retType->arrayDim = 0;
        retType->arraySizes = NULL;
        return retType;
    }
    // STRUCT Tag
    else if (node->child_count == 2) {
        Node *tag = node->children[1];
        char *structName = tag->children[0]->value;
        Symbol *structSym = findSymbol(structName);
        if (!structSym || structSym->kind != STRUCT_KIND) {
            printError(17, node->lineNo, "Undefined struct used");
            return NULL;
        }
        Type *retType = malloc(sizeof(Type));
        retType->kind = STRUCTURE_TYPE;
        retType->structType = structSym;
        retType->base = NULL;
        retType->arrayDim = 0;
        retType->arraySizes = NULL;
        return retType;
    }
    return NULL;
}

// ==================== 函数定义 ====================
void handleFuncDef(Node *funDec, Type *retType, Node *compSt) {
    if (!funDec)
        return;
    char *funcName = funDec->children[0]->value;
    int line = funDec->children[0]->lineNo;
    // printf("DEBUG: 处理函数定义 '%s' 在第 %d 行\n", funcName, line);

    int argNum = 0;
    Symbol **argList = NULL;
    if (funDec->child_count == 4) {
        Node *varList = funDec->children[2];
        Node *curVarList = varList;
        while (curVarList && curVarList->child_count > 0) {
            argNum++;
            if (curVarList->child_count == 3)
                curVarList = curVarList->children[2];
            else
                break;
        }
        argList = argNum > 0 ? malloc(sizeof(Symbol *) * argNum) : NULL;
        int idx = 0;
        curVarList = varList;
        while (curVarList && curVarList->child_count > 0) {
            Node *paramDec = curVarList->children[0];
            Type *paramType = getType(paramDec->children[0]);
            Node *varDec = paramDec->children[1];
            // 递归查找参数名的 ID 节点，兼容数组参数
            Node *idNode = varDec;
            while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) {
                idNode = idNode->children[0];
            }
            if (!idNode || strcmp(idNode->type, "ID") != 0) {
                // 无法找到参数名，跳过此参数
                if (curVarList->child_count == 3)
                    curVarList = curVarList->children[2];
                else
                    break;
                continue;
            }
            char *paramName = idNode->value;
            int paramLine = idNode->lineNo;
            // 处理数组
            Type *finalType = paramType;
            Node *curVar = varDec;
            while (curVar->child_count == 4) {
                Type *arr = malloc(sizeof(Type));
                arr->kind = ARRAY_TYPE;
                arr->base = finalType;
                arr->arrayDim = 1;
                arr->arraySizes = malloc(sizeof(int));
                arr->arraySizes[0] = atoi(curVar->children[2]->value);
                arr->structType = NULL;
                finalType = arr;
                curVar = curVar->children[0];
            }
            argList[idx++] = createVariableSymbol(paramName, finalType, paramLine);
            if (curVarList->child_count == 3)
                curVarList = curVarList->children[2];
            else
                break;
        }
    }
    Symbol *funcSym = createFunctionSymbol(funcName, retType, line, argNum, argList);
    if (error_code == 3) {
        printError(3, line, "Function parameter name redefined");
        return;
    }
    Symbol *exist = findSymbol(funcName);
    if (exist && exist->kind == FUNC_KIND) {
        if (exist->info.func_info.isDefined) {
            printError(4, line, "Function redefined");
            return;
        } else {
            // 检查声明和定义一致
            if (exist->info.func_info.argNum != funcSym->info.func_info.argNum ||
                !TypeEqual(exist->info.func_info.return_type, funcSym->info.func_info.return_type)) {
                printError(19, line, "Function declaration and definition mismatch");
                return;
            }
            for (int i = 0; i < funcSym->info.func_info.argNum; i++) {
                if (!TypeEqual(exist->info.func_info.arg_list[i]->info.var_info.type,
                               funcSym->info.func_info.arg_list[i]->info.var_info.type)) {
                    printError(19, line, "Function parameter type mismatch");
                }
            }
            exist->info.func_info.isDefined = true;
        }
    } else {
        funcSym->info.func_info.isDefined = true;
        insertSymbol(funcSym);
        if (error_code != 0)
            printError(error_code, line, "Function insert error");
    }
    /* 函数体处理：先进入作用域，再插入参数符号，然后处理函数体内部
       不通过 traverseCompSt（避免双重 enter），而是直接处理 DefList 和 StmtList */
    enterScope();
    for (int i = 0; i < argNum; i++) {
        // 检查参数名是否与结构体名冲突
        Symbol *existing = findSymbol(argList[i]->name);
        if (existing && existing->kind == STRUCT_KIND) {
            printError(3, argList[i]->lineno, "Variable name conflicts with struct name");
        } else {
            insertSymbol(argList[i]);
            if (error_code != 0)
                printError(error_code, argList[i]->lineno, "Function parameter insert error");
        }
    }
    // 直接处理函数体的 DefList 和 StmtList，不调用 traverseCompSt（避免双重作用域）
    if (compSt && compSt->child_count >= 3) {
        Node *defList = compSt->children[1];
        Node *stmtList = compSt->children[2];
        traverseDefList(defList);
        traverseStmtList(stmtList, retType);
    }
    exitScope();
}

// ==================== 语句块/语句 ====================
void traverseCompSt(Node *node, Type *retType) {
    if (!node || node->child_count < 4)
        return;
    // 通用复合语句：进入新的作用域 -> 处理内容 -> 退出作用域
    // 调试输出以验证 enter/exit 是否被调用（遇到问题时可删除）
    enterScope();
    Node *defList = node->children[1];
    Node *stmtList = node->children[2];
    traverseDefList(defList);
    traverseStmtList(stmtList, retType);
    exitScope();
}

void traverseStmtList(Node *node, Type *retType) {
    if (!node || node->child_count == 0)
        return;
    traverseStmt(node->children[0], retType);
    if (node->child_count == 2)
        traverseStmtList(node->children[1], retType);
}

void traverseStmt(Node *node, Type *retType) {
    if (!node || node->child_count == 0)
        return;
    Node *first = node->children[0];
    if (strcmp(first->type, "Exp") == 0) {
        checkExp(first);
    } else if (strcmp(first->type, "CompSt") == 0) {
        // debug: entering nested CompSt
        traverseCompSt(first, retType);
    } else if (strcmp(first->type, "RETURN") == 0) {
        Type *expType = checkExp(node->children[1]);
        if (!TypeEqual(retType, expType))
            printError(8, node->children[0]->lineNo, "Type mismatched for return");
    } else if (strcmp(first->type, "IF") == 0) {
        checkExp(node->children[2]);
        traverseStmt(node->children[4], retType);
        if (node->child_count == 7)
            traverseStmt(node->children[6], retType);
    } else if (strcmp(first->type, "WHILE") == 0) {
        checkExp(node->children[2]);
        traverseStmt(node->children[4], retType);
    }
}

// ==================== 表达式检查 ====================
Type *checkExp(Node *exp) {
    if (!exp || exp->child_count == 0)
        return NULL;
    Node *c = exp->children[0];
    // ID
    if (strcmp(c->type, "ID") == 0 && exp->child_count == 1) {
        // printf("DEBUG: 检查ID节点 '%s' 在第 %d 行\n", c->value, c->lineNo);
        Symbol *sym = findSymbol(c->value);
        if (!sym) {
            printError(1, c->lineNo, "Undefined variable");
            return NULL;
        }
        if (sym->kind == VAR_KIND)
            return sym->info.var_info.type;
        if (sym->kind == STRUCT_KIND) {
            printError(1, c->lineNo, "Struct name used as variable");
            return NULL;
        }
        if (sym->kind == FUNC_KIND) {
            printError(11, c->lineNo, "Function name used as variable");
            return NULL;
        }
    }
    // INT
    if (strcmp(c->type, "INT") == 0) {
        Type *t = malloc(sizeof(Type));
        t->kind = INT_TYPE;
        t->base = NULL;
        t->arrayDim = 0;
        t->arraySizes = NULL;
        t->structType = NULL;
        return t;
    }
    // FLOAT
    if (strcmp(c->type, "FLOAT") == 0) {
        Type *t = malloc(sizeof(Type));
        t->kind = FLOAT_TYPE;
        t->base = NULL;
        t->arrayDim = 0;
        t->arraySizes = NULL;
        t->structType = NULL;
        return t;
    }
    // 赋值
    if (exp->child_count == 3 && strcmp(exp->children[1]->type, "ASSIGNOP") == 0) {
        Type *left = checkExp(exp->children[0]);
        Type *right = checkExp(exp->children[2]);
        if (!isLValue(exp->children[0]))
            printError(6, exp->children[0]->lineNo, "The left-hand side of an assignment must be a variable");
        if (left != NULL && right != NULL && !TypeEqual(left, right))
            printError(5, exp->children[0]->lineNo, "Type mismatched for assignment");
        return left;
    }
    // 算术运算
    if (exp->child_count == 3 &&
        (strcmp(exp->children[1]->type, "PLUS") == 0 ||
         strcmp(exp->children[1]->type, "MINUS") == 0 ||
         strcmp(exp->children[1]->type, "STAR") == 0 ||
         strcmp(exp->children[1]->type, "DIV") == 0)) {
        Type *left = checkExp(exp->children[0]);
        Type *right = checkExp(exp->children[2]);
        if (!left || !right)
            return NULL;
        if (left->kind != INT_TYPE && left->kind != FLOAT_TYPE)
            printError(7, exp->children[0]->lineNo, "Operand type mismatched for arithmetic");
        if (right->kind != INT_TYPE && right->kind != FLOAT_TYPE)
            printError(7, exp->children[2]->lineNo, "Operand type mismatched for arithmetic");
        if (!TypeEqual(left, right))
            printError(7, exp->children[1]->lineNo, "Operand type mismatched for arithmetic");
        return left;
    }
    // 逻辑运算
    if (exp->child_count == 3 &&
        (strcmp(exp->children[1]->type, "AND") == 0 ||
         strcmp(exp->children[1]->type, "OR") == 0 ||
         strcmp(exp->children[1]->type, "RELOP") == 0)) {
        Type *left = checkExp(exp->children[0]);
        Type *right = checkExp(exp->children[2]);
        if (!left || !right)
            return NULL;
        if (left->kind != INT_TYPE && left->kind != FLOAT_TYPE)
            printError(7, exp->children[0]->lineNo, "Operand type mismatched for logic");
        if (right->kind != INT_TYPE && right->kind != FLOAT_TYPE)
            printError(7, exp->children[2]->lineNo, "Operand type mismatched for logic");
        return left;
    }
    // LP Exp RP
    if (exp->child_count == 3 && strcmp(c->type, "LP") == 0)
        return checkExp(exp->children[1]);
    // MINUS/NOT
    if (exp->child_count == 2 &&
        (strcmp(c->type, "MINUS") == 0 || strcmp(c->type, "NOT") == 0)) {
        Type *t = checkExp(exp->children[1]);
        if (!t)
            return NULL;
        if (t->kind != INT_TYPE && t->kind != FLOAT_TYPE)
            printError(7, exp->children[1]->lineNo, "Operand type mismatched for unary");
        return t;
    }
    // 函数调用
    if (exp->child_count >= 3 && strcmp(c->type, "ID") == 0 &&
        strcmp(exp->children[1]->type, "LP") == 0) {
        Symbol *sym = findSymbol(c->value);
        if (!sym) {
            printError(2, c->lineNo, "Undefined function");
            return NULL;
        }
        if (sym->kind != FUNC_KIND) {
            printError(11, c->lineNo, "Not a function");
            return NULL;
        }
        if (!sym->info.func_info.isDefined)
            printError(2, c->lineNo, "Function declared but not defined");
        int expectedArgNum = sym->info.func_info.argNum;
        if (exp->child_count == 4) { // 有参数
            Node *argsNode = exp->children[2];
            int actualArgNum = 0;
            Node *cur = argsNode;
            while (cur && cur->child_count > 0) {
                actualArgNum++;
                if (cur->child_count == 3)
                    cur = cur->children[2];
                else
                    break;
            }
            if (actualArgNum != expectedArgNum)
                printError(9, c->lineNo, "Function argument number mismatch");
            else {
                cur = argsNode;
                int idx = 0;
                while (cur && cur->child_count > 0 && idx < expectedArgNum) {
                    Type *argType = checkExp(cur->children[0]);
                    Type *paramType = sym->info.func_info.arg_list[idx]->info.var_info.type;
                    if (!TypeEqual(argType, paramType))
                        printError(9, c->lineNo, "Function argument type mismatch");
                    idx++;
                    if (cur->child_count == 3)
                        cur = cur->children[2];
                    else
                        break;
                }
            }
        } else {
            if (expectedArgNum != 0)
                printError(9, c->lineNo, "Function argument number mismatch");
        }
        return sym->info.func_info.return_type;
    }
    // 数组访问
    if (exp->child_count == 4 && strcmp(exp->children[1]->type, "LB") == 0) {
        Type *arrType = checkExp(exp->children[0]);
        Type *idxType = checkExp(exp->children[2]);

        // 检查数组索引类型
        if (!idxType || idxType->kind != INT_TYPE)
            printError(12, exp->children[2]->lineNo, "Array index is not integer");

        // 如果数组变量不存在，返回NULL
        if (!arrType) {
            return NULL;
        }

        // 检查是否真的是数组类型
        if (arrType->kind != ARRAY_TYPE)
            printError(10, exp->children[0]->lineNo, "Not an array");

        return arrType->base;
    }
    // 结构体成员访问
    if (exp->child_count == 3 && strcmp(exp->children[1]->type, "DOT") == 0) {
        Type *structType = checkExp(exp->children[0]);
        if (!structType || structType->kind != STRUCTURE_TYPE) {
            printError(13, exp->children[0]->lineNo, "Not a struct");
            return NULL;
        }
        Symbol *field = getStructField(structType->structType, exp->children[2]->value);
        if (!field) {
            printError(14, exp->children[2]->lineNo, "Struct field not found");
            return NULL;
        }
        return field->info.var_info.type;
    }
    return NULL;
}

Symbol *getStructField(Symbol *structSym, char *fieldName) {
    if (structSym == NULL || structSym->kind != STRUCT_KIND)
        return NULL;
    for (int i = 0; i < structSym->info.struct_info.symbolNum; i++) {
        Symbol *field = structSym->info.struct_info.symbol_list[i];
        if (strcmp(field->name, fieldName) == 0) {
            return field;
        }
    }

    return NULL;
}

// ==================== 资源释放 ====================
void freeSemanticResource(void) {
    extern int top;
    extern Symbol *stak[];

    // exitScope 已经在每次调用时释放了对应层的符号
    // 这里只需要确保所有作用域都被清理
    // 如果 top >= 0，说明还有未退出的作用域，需要手动清理
    while (top >= 0) {
        freeSymbolStack(top);
        top--;
    }
}