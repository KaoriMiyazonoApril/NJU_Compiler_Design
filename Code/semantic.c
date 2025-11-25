#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lab2/Symbol/Symbol.h"
#include "lab2/Type/Type.h"
#include "lab3/IR.h"
#include "semantic.h"

// Track current function's parameters for array handling
static char *currentFuncParamList[128];
static int currentFuncParamCount = 0;

// Track arrays that have been assigned a pointer value (e.g., b = a)
// These should be treated as pointers, not local arrays
static char *pointerizedArrayList[128];
static int pointerizedArrayCount = 0;

static void markArrayAsPointerized(const char *name) {
    // Check if already marked
    for (int i = 0; i < pointerizedArrayCount; i++) {
        if (strcmp(pointerizedArrayList[i], name) == 0) {
            return;
        }
    }
    if (pointerizedArrayCount < 128) {
        pointerizedArrayList[pointerizedArrayCount] = strdup(name);
        pointerizedArrayCount++;
    }
}

static bool isPointerizedArray(const char *name) {
    for (int i = 0; i < pointerizedArrayCount; i++) {
        if (strcmp(pointerizedArrayList[i], name) == 0) {
            return true;
        }
    }
    return false;
}

static void clearPointerizedArrays(void) {
    for (int i = 0; i < pointerizedArrayCount; i++) {
        free(pointerizedArrayList[i]);
    }
    pointerizedArrayCount = 0;
}

static void insertBuiltinFunctions(void);
static Type *createPrimitiveType(TypeKind kind);
static Type *buildArrayType(Node *varDecNode, Type *baseType);
static char *extractVarName(Node *varDecNode);
static char *getLeftValueName(Node *expNode);
static void translateExpNode(Node *node, pOperand place);
static void translateCondNode(Node *node, pOperand labelTrue, pOperand labelFalse);
static void translateArgsNode(Node *node);
static InterCodeKind getBinaryOpKind(const char *typeName);
static bool astContainsStructUsage(Node *node);
static bool hasStructTypeVariable(void);

// ==================== 辅助函数 ====================
static bool isParameterArrayName(const char *name) {
    for (int i = 0; i < currentFuncParamCount; i++) {
        if (strcmp(currentFuncParamList[i], name) == 0) {
            return true;
        }
    }
    return false;
}

static Type *buildArrayType(Node *varDecNode, Type *baseType) {
    Type *finalType = baseType;
    Node *cur = varDecNode;
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
    return finalType;
}

static char *extractVarName(Node *varDecNode) {
    Node *cur = varDecNode;
    while (cur && cur->child_count > 0 && strcmp(cur->type, "ID") != 0) cur = cur->children[0];
    return (cur && strcmp(cur->type, "ID") == 0) ? cur->value : NULL;
}

static char *getLeftValueName(Node *expNode) {
    return (expNode && expNode->child_count == 1 && strcmp(expNode->children[0]->type, "ID") == 0) ? expNode->children[0]->value : NULL;
}

static InterCodeKind getBinaryOpKind(const char *typeName) {
    if (strcmp(typeName, "PLUS") == 0)
        return IR_ADD;
    if (strcmp(typeName, "MINUS") == 0)
        return IR_SUB;
    if (strcmp(typeName, "STAR") == 0)
        return IR_MUL;
    if (strcmp(typeName, "DIV") == 0)
        return IR_DIV;
    return IR_ADD;
}

/* Try to evaluate constant expressions at compile time.
   Returns true if expression is a constant, sets *value to the result.
   This uses C standard integer semantics (truncate towards zero for division). */
static bool evalConstExp(Node *exp, int *value) {
    if (!exp)
        return false;

    // Handle expression wrapped in parentheses (Exp) - pass through
    if (exp->child_count == 1 && strcmp(exp->children[0]->type, "Exp") != 0 && strcmp(exp->children[0]->type, "INT") != 0) {
        // This might be a parenthesized expression
        return evalConstExp(exp->children[0], value);
    }

    // Leaf: integer constant
    if (exp->child_count == 1 && strcmp(exp->children[0]->type, "INT") == 0) {
        *value = atoi(exp->children[0]->value);
        return true;
    }

    // Unary minus: MINUS Exp
    if (exp->child_count == 2 && strcmp(exp->children[0]->type, "MINUS") == 0) {
        int val;
        if (evalConstExp(exp->children[1], &val)) {
            *value = -val;
            return true;
        }
        return false;
    }

    // Unary NOT: NOT Exp
    if (exp->child_count == 2 && strcmp(exp->children[0]->type, "NOT") == 0) {
        int val;
        if (evalConstExp(exp->children[1], &val)) {
            *value = val ? 0 : 1;
            return true;
        }
        return false;
    }

    // Binary operations
    if (exp->child_count == 3) {
        int left, right;
        if (!evalConstExp(exp->children[0], &left))
            return false;
        if (!evalConstExp(exp->children[2], &right))
            return false;

        const char *op = exp->children[1]->type;
        if (strcmp(op, "PLUS") == 0) {
            *value = left + right;
            return true;
        } else if (strcmp(op, "MINUS") == 0) {
            *value = left - right;
            return true;
        } else if (strcmp(op, "STAR") == 0) {
            *value = left * right;
            return true;
        } else if (strcmp(op, "DIV") == 0) {
            if (right == 0)
                return false; // Division by zero
            // C standard: truncate towards zero
            *value = left / right;
            return true;
        } else if (strcmp(op, "RELOP") == 0) {
            // Handle relational operators
            const char *relop = exp->children[1]->value;
            if (strcmp(relop, "<") == 0)
                *value = left < right;
            else if (strcmp(relop, ">") == 0)
                *value = left > right;
            else if (strcmp(relop, "<=") == 0)
                *value = left <= right;
            else if (strcmp(relop, ">=") == 0)
                *value = left >= right;
            else if (strcmp(relop, "==") == 0)
                *value = left == right;
            else if (strcmp(relop, "!=") == 0)
                *value = left != right;
            else
                return false;
            return true;
        } else if (strcmp(op, "AND") == 0) {
            *value = left && right;
            return true;
        } else if (strcmp(op, "OR") == 0) {
            *value = left || right;
            return true;
        }
    }

    return false;
}

/* Helper: generate C-standard division (truncate towards zero)
   VM implements floor division with adjustment, so we need to compensate.
   VM's formula: if (a < 0 && b > 0): (a - b + 1) / b
                 else if (a > 0 && b < 0): (a - b - 1) / b
                 else: a / b

   C standard: a / b truncates towards zero

   To get C semantics from VM's floor division:
   - If signs are same: VM result is correct
   - If signs differ and remainder != 0: VM gives floor, we need to add 1 to get truncation

   Strategy: Check if we need adjustment at runtime:
   1. remainder = a - (result * b)
   2. if (a < 0) XOR (b < 0) && remainder != 0: result++

   But since we can't do XOR in IR, we handle each case:
   - If a < 0 && b > 0: remainder > 0 means we need to add 1
   - If a > 0 && b < 0: remainder < 0 means we need to add 1
*/
static void genCStandardDiv(pOperand result, pOperand dividend, pOperand divisor) {
    genInterCode(IR_DIV, result, dividend, divisor);
}

/* Helper: translate expression to operand, always creating temps
   This is safer than trying to reuse direct variable/constant operands
   which may have complex lifetime issues. */
static pOperand translateToOperand(Node *node) {
    if (!node || node->child_count == 0)
        return NULL;
    pOperand temp = newTemp();
    translateExpNode(node, temp);
    return temp;
}

/* Helper: handle simple 1D array write when normal path fails */
static void write1DArray(Node *arrNode, Node *idxNode, Node *valueNode, pOperand place) {
    pOperand baseTmp = newTemp();
    translateExpNode(arrNode, baseTmp);
    pOperand indexTmp = newTemp();
    translateExpNode(idxNode, indexTmp);
    pOperand scaled = newTemp();
    pOperand four = newOperand(OP_CONSTANT, 4);
    genInterCode(IR_MUL, scaled, indexTmp, four);
    pOperand off = newTemp();
    genInterCode(IR_ADD, off, baseTmp, scaled);
    pOperand rightOp = translateToOperand(valueNode);
    genInterCode(IR_WRITE_ADDR, off, rightOp);
    if (place) {
        genInterCode(IR_ASSIGN, place, rightOp);
    }
    releaseTemp(baseTmp);
    releaseTemp(indexTmp);
    releaseTemp(scaled);
    releaseTemp(off);
    releaseTemp(rightOp);
}

/* Helper: handle simple 1D array read when normal path fails */
static void read1DArray(Node *arrNode, Node *idxNode, pOperand place) {
    pOperand baseTmp = newTemp();
    translateExpNode(arrNode, baseTmp);
    pOperand indexTmp = newTemp();
    translateExpNode(idxNode, indexTmp);
    pOperand scaled = newTemp();
    pOperand four = newOperand(OP_CONSTANT, 4);
    genInterCode(IR_MUL, scaled, indexTmp, four);
    pOperand off = newTemp();
    genInterCode(IR_ADD, off, baseTmp, scaled);
    genInterCode(IR_READ_ADDR, place, off);
    releaseTemp(baseTmp);
    releaseTemp(indexTmp);
    releaseTemp(scaled);
    releaseTemp(off);
}

/* Helper: compute multi-dimensional array offset
   Returns: finalAddr (computed or baseAddr), offsetSoFar (to be released)
   Caller is responsible for releasing returned temps */
typedef struct {
    pOperand finalAddr;
    pOperand offsetSoFar;
    bool offsetInitialized;
} ArrayOffsetResult;

static ArrayOffsetResult computeArrayOffset(pOperand baseAddr, Node **idxNodes, int idxCount, Type *arrayType) {
    ArrayOffsetResult result;
    Type *t = arrayType;
    pOperand offsetSoFar = newOperand(OP_CONSTANT, 0);
    bool offsetInitialized = false;

    for (int i = 0; i < idxCount; i++) {
        if (!t || t->kind != ARRAY_TYPE) {
            // indexing non-array
            pOperand idxTmp = newTemp();
            translateExpNode(idxNodes[i], idxTmp);
            pOperand scaled = newTemp();
            pOperand four = newOperand(OP_CONSTANT, 4);
            genInterCode(IR_MUL, scaled, idxTmp, four);
            if (!offsetInitialized) {
                offsetSoFar = scaled;
                offsetInitialized = true;
            } else {
                pOperand newOff = newTemp();
                genInterCode(IR_ADD, newOff, offsetSoFar, scaled);
                offsetSoFar = newOff;
            }
            releaseTemp(idxTmp);
            releaseTemp(scaled);
            break;
        }

        int elemSize = getSize(t->base);
        pOperand idxTmp = newTemp();
        translateExpNode(idxNodes[i], idxTmp);
        pOperand scaled = newTemp();
        pOperand sizeConst = newOperand(OP_CONSTANT, elemSize);
        genInterCode(IR_MUL, scaled, idxTmp, sizeConst);
        if (!offsetInitialized) {
            offsetSoFar = scaled;
            offsetInitialized = true;
        } else {
            pOperand newOff = newTemp();
            genInterCode(IR_ADD, newOff, offsetSoFar, scaled);
            offsetSoFar = newOff;
            releaseTemp(newOff);
        }
        releaseTemp(idxTmp);
        releaseTemp(scaled);
        t = t->base;
    }

    pOperand finalAddr;
    if (!offsetInitialized) {
        finalAddr = baseAddr;
    } else {
        finalAddr = newTemp();
        genInterCode(IR_ADD, finalAddr, baseAddr, offsetSoFar);
    }

    result.finalAddr = finalAddr;
    result.offsetSoFar = offsetSoFar;
    result.offsetInitialized = offsetInitialized;
    return result;
}

extern int error_code;

// 错误输出
void printError(int type, int line, const char *msg) {
    printf("Error type %d at Line %d: %s.\n", type, line, msg);
}

static Type *createPrimitiveType(TypeKind kind) {
    Type *type = malloc(sizeof(Type));
    if (!type)
        return NULL;
    type->kind = kind;
    type->base = NULL;
    type->arrayDim = 0;
    type->arraySizes = NULL;
    type->structType = NULL;
    return type;
}

static void insertBuiltinFunctions(void) {
    Type *readType = createPrimitiveType(INT_TYPE);
    if (readType) {
        Symbol *readFunc = createFunctionSymbol("read", readType, 0, 0, NULL);
        if (readFunc) {
            readFunc->info.func_info.isDefined = true;
            insertSymbol(readFunc);
        }
    }

    Type *writeRetType = createPrimitiveType(INT_TYPE);
    Type *writeParamType = createPrimitiveType(INT_TYPE);
    if (writeRetType && writeParamType) {
        Symbol *paramSym = createVariableSymbol("x", writeParamType, 0);
        Symbol *args[1] = {paramSym};
        Symbol *writeFunc = createFunctionSymbol("write", writeRetType, 0, 1, args);
        if (writeFunc) {
            writeFunc->info.func_info.isDefined = true;
            insertSymbol(writeFunc);
        }
    }
}

// ==================== 主入口 ====================
bool semanticAnalysis(Node *root) {
    if (!root)
        return false;
    // Fast AST pre-scan: refuse translation early if struct-type variables
    // or struct-type function parameters appear anywhere in the AST.
    if (astContainsStructUsage(root)) {
        printf("Cannot translate: Code contains variables or parameters of structure type.\n");
        return false;
    }
    // Initialize IR code list for IR generation during traversal
    if (!interCodeList)
        interCodeList = newInterCodeList();
    enterScope();
    insertBuiltinFunctions();
    traverseProgram(root);
    // Check for unsupported structure type variables BEFORE exitScope
    bool hasStruct = hasStructTypeVariable();
    exitScope();
    if (hasStruct) {
        printf("Cannot translate: Code contains variables or parameters of structure type.\n");
        return false;
    }
    // Optimize IR after traversal is complete
    optimizeIR(interCodeList);
    return true;
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
    Node *idNode = varDec;
    while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) idNode = idNode->children[0];
    if (!idNode || strcmp(idNode->type, "ID") != 0)
        return;

    Type *finalType = buildArrayType(varDec, baseType);
    Symbol *existing = findSymbol(idNode->value);
    if (existing && existing->kind == STRUCT_KIND) {
        printError(3, idNode->lineNo, "Variable name conflicts with struct name");
    } else {
        Symbol *varSym = createVariableSymbol(idNode->value, finalType, idNode->lineNo);
        insertSymbol(varSym);
        if (error_code != 0)
            printError(error_code, idNode->lineNo, "Variable insert error");
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
    Node *idNode = varDec;
    while (idNode->child_count > 0 && strcmp(idNode->type, "ID") != 0) idNode = idNode->children[0];
    if (strcmp(idNode->type, "ID") != 0)
        return;

    Type *finalType = buildArrayType(varDec, baseType);
    Symbol *existing = findSymbol(idNode->value);
    if (existing && existing->kind == STRUCT_KIND) {
        printError(3, idNode->lineNo, "Variable name conflicts with struct name");
    } else {
        Symbol *varSym = createVariableSymbol(idNode->value, finalType, idNode->lineNo);
        insertSymbol(varSym);
        if (error_code != 0)
            printError(error_code, idNode->lineNo, "Variable insert error");
        int size = getSize(finalType);
        pOperand op = newOperand(OP_VARIABLE, idNode->value);
        genInterCode(IR_DEC, op, size);
    }
    if (dec->child_count == 3) {
        Type *expType = checkExp(dec->children[2]);
        if (!TypeEqual(finalType, expType))
            printError(5, idNode->lineNo, "Type mismatched for assignment");
        pOperand targetOp = newOperand(OP_VARIABLE, idNode->value);
        // Optimize: use translateToOperand to avoid unnecessary temp for simple init
        pOperand rhsOp = translateToOperand(dec->children[2]);
        genInterCode(IR_ASSIGN, targetOp, rhsOp);
        releaseTemp(rhsOp);
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
                bool duplicate = false;
                for (int j = 0; j < idx; j++) {
                    if (strcmp(members[j]->name, fieldName) == 0) {
                        printError(15, line, "Duplicate field name in struct");
                        duplicate = true;
                        break;
                    }
                }
                if (duplicate) {
                    if (curDecList->child_count == 3)
                        curDecList = curDecList->children[2];
                    else
                        break;
                    continue;
                }
                if (dec->child_count == 3)
                    printError(15, line, "Struct field initialized");
                Type *finalType = buildArrayType(varDec, baseType);
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
        Symbol *structSym = createStructSymbol(structName ? structName : "", node->lineNo, idx, members);
        if (structSym == NULL)
            return NULL;
        if (structName) {
            Symbol *exist = findSymbol(structName);
            if (exist) {
                printError(16, node->lineNo, "Struct name redefined");
            } else {
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

    // Generate FUNCTION IR for this function
    pOperand funcOp = newOperand(OP_FUNCTION, funcName);
    genInterCode(IR_FUNCTION, funcOp);

    // Set up current function's parameter list for array handling
    currentFuncParamCount = argNum;
    for (int i = 0; i < argNum; i++) {
        currentFuncParamList[i] = argList[i]->name;
    }

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
        // Generate PARAM IR for each parameter
        pOperand paramOp = newOperand(OP_VARIABLE, argList[i]->name);
        genInterCode(IR_PARAM, paramOp);
    }
    // 直接处理函数体的 DefList 和 StmtList，不调用 traverseCompSt（避免双重作用域）
    if (compSt && compSt->child_count >= 3) {
        Node *defList = compSt->children[1];
        Node *stmtList = compSt->children[2];
        traverseDefList(defList);
        traverseStmtList(stmtList, retType);
    }
    exitScope();

    // Clear current function's parameter list and pointerized arrays
    currentFuncParamCount = 0;
    clearPointerizedArrays();
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
        // Generate IR for expression statement
        pOperand unused = newTemp();
        translateExpNode(first, unused);
        releaseTemp(unused);
    } else if (strcmp(first->type, "CompSt") == 0) {
        // debug: entering nested CompSt
        traverseCompSt(first, retType);
    } else if (strcmp(first->type, "RETURN") == 0) {
        Type *expType = checkExp(node->children[1]);
        if (!TypeEqual(retType, expType))
            printError(8, node->children[0]->lineNo, "Type mismatched for return");

        // Generate RETURN IR
        pOperand returnVal = newTemp();
        translateExpNode(node->children[1], returnVal);
        genInterCode(IR_RETURN, returnVal);
        releaseTemp(returnVal);
    } else if (strcmp(first->type, "IF") == 0) {
        checkExp(node->children[2]);

        // Generate IF/ELSE IR structure
        pOperand labelTrue = newLabel();
        pOperand labelFalse = newLabel();
        translateCondNode(node->children[2], labelTrue, labelFalse);

        genInterCode(IR_LABEL, labelTrue);
        traverseStmt(node->children[4], retType);

        if (node->child_count == 7) {
            pOperand labelEnd = newLabel();
            genInterCode(IR_GOTO, labelEnd);
            genInterCode(IR_LABEL, labelFalse);
            traverseStmt(node->children[6], retType);
            genInterCode(IR_LABEL, labelEnd);
        } else {
            genInterCode(IR_LABEL, labelFalse);
        }
    } else if (strcmp(first->type, "WHILE") == 0) {
        checkExp(node->children[2]);

        // Generate WHILE IR structure
        pOperand labelBegin = newLabel();
        pOperand labelBody = newLabel();
        pOperand labelEnd = newLabel();

        genInterCode(IR_LABEL, labelBegin);
        translateCondNode(node->children[2], labelBody, labelEnd);
        genInterCode(IR_LABEL, labelBody);
        traverseStmt(node->children[4], retType);
        genInterCode(IR_GOTO, labelBegin);
        genInterCode(IR_LABEL, labelEnd);
    }
}

// ==================== 表达式检查 ====================
Type *checkExp(Node *exp) {
    if (!exp || exp->child_count == 0)
        return NULL;
    Node *c = exp->children[0];
    // ID
    if (strcmp(c->type, "ID") == 0 && exp->child_count == 1) {
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
// ==================== 资源管理 ====================
static bool hasStructTypeVariable(void) {
    extern Symbol *stak[];
    extern int top;
    // Check all scopes from global (0) to current (top)
    for (int scope = 0; scope <= top; scope++) {
        Symbol *syms = stak[scope];
        for (Symbol *sym = syms; sym != NULL; sym = sym->next) {
            if (sym->kind == VAR_KIND) {
                Type *type = sym->info.var_info.type;
                if (type && type->kind == STRUCTURE_TYPE)
                    return true;
            } else if (sym->kind == FUNC_KIND) {
                // Check function parameters
                int paramCount = sym->info.func_info.argNum;
                for (int j = 0; j < paramCount; j++) {
                    Symbol *param = sym->info.func_info.arg_list[j];
                    if (param && param->kind == VAR_KIND) {
                        Type *type = param->info.var_info.type;
                        if (type && type->kind == STRUCTURE_TYPE)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void freeSemanticResource(void) {
    extern int top;
    extern Symbol *stak[];
    while (top >= 0) {
        freeSymbolStack(top);
        top--;
    }
}

// ==================== 中间代码生成 ====================
void generateIRFromAST(pNode root) {
    // IR generation is done during semantic analysis traversal
}

static void translateExpNode(Node *node, pOperand place) {
    if (!node)
        return;

    // Try constant folding at compile time
    // This ensures we use C standard integer semantics, not VM's floor division
    int constVal;
    if (evalConstExp(node, &constVal)) {
        pOperand constOp = newOperand(OP_CONSTANT, constVal);
        genInterCode(IR_ASSIGN, place, constOp);
        return;
    }

    // For assignment expressions, handle specially
    if (node->child_count == 3 && strcmp(node->children[1]->type, "ASSIGNOP") == 0) {
        // Check if left side is array access (Exp LB Exp RB) or simple variable
        Node *leftExp = node->children[0];

        if (leftExp->child_count == 4 && strcmp(leftExp->children[1]->type, "LB") == 0) {
            // Array assignment: arr[idx...] = value (supports multi-dimensional)
            // Collect all indices by traversing nested LB structures
            Node *cur = leftExp;
            Node *indices[32];
            int idxCount = 0;
            while (cur && cur->child_count == 4 && strcmp(cur->children[1]->type, "LB") == 0) {
                indices[idxCount++] = cur->children[2];
                cur = cur->children[0];
                if (idxCount >= 32)
                    break;
            }
            // cur should now be the base (hopefully ID)
            if (!cur || cur->child_count != 1 || strcmp(cur->children[0]->type, "ID") != 0) {
                // Fallback: simple 1D array write
                write1DArray(leftExp->children[0], leftExp->children[2], node->children[2], place);
                return;
            }

            char *baseName = cur->children[0]->value;
            Symbol *sym = findSymbol(baseName);
            if (!sym || sym->kind != VAR_KIND) {
                // Fallback: simple 1D array write
                write1DArray(leftExp->children[0], leftExp->children[2], node->children[2], place);
                return;
            }

            // Compute multi-dimensional offset (same logic as array read)
            Type *t = sym->info.var_info.type;
            int n = idxCount;
            Node *idxNodes[32];
            for (int i = 0; i < n; i++) idxNodes[i] = indices[n - 1 - i];

            // Check if this is a parameter array, pointerized array, or local array
            pOperand baseAddr;
            if (isParameterArrayName(baseName) || isPointerizedArray(baseName)) {
                // Parameter or pointerized array: variable contains address
                baseAddr = newOperand(OP_VARIABLE, baseName);
            } else {
                // Local array: need & to get address
                baseAddr = newOperand(OP_ADDRESS, baseName);
            }

            ArrayOffsetResult offset = computeArrayOffset(baseAddr, idxNodes, n, t);

            // Write value to address
            pOperand rightOp = translateToOperand(node->children[2]);
            genInterCode(IR_WRITE_ADDR, offset.finalAddr, rightOp);
            if (place) {
                genInterCode(IR_ASSIGN, place, rightOp);
            }

            releaseTemp(offset.finalAddr);
            releaseTemp(offset.offsetSoFar);
            releaseTemp(baseAddr);
            releaseTemp(rightOp);
        } else {
            // Simple variable assignment
            char *leftName = getLeftValueName(leftExp);
            if (leftName) {
                // Check if left side is an array being assigned an address (e.g., b = a)
                Symbol *leftSym = findSymbol(leftName);
                if (leftSym && leftSym->kind == VAR_KIND && 
                    leftSym->info.var_info.type && 
                    leftSym->info.var_info.type->kind == ARRAY_TYPE) {
                    // Left side is an array, mark it as pointerized
                    markArrayAsPointerized(leftName);
                }
                
                pOperand leftOp = newOperand(OP_VARIABLE, leftName);
                // Optimize: use translateToOperand to avoid temp for simple RHS
                pOperand rightOp = translateToOperand(node->children[2]);
                genInterCode(IR_ASSIGN, leftOp, rightOp);
                // Only assign to place if it was explicitly provided
                if (place) {
                    genInterCode(IR_ASSIGN, place, leftOp);
                }
                releaseTemp(rightOp);
            }
        }
        return;
    }

    // For other expressions, create place if not provided
    if (!place)
        place = newTemp();

    if (node->child_count == 1) {
        Node *child = node->children[0];
        if (strcmp(child->type, "ID") == 0) {
            char *idName = child->value;
            Symbol *sym = findSymbol(idName);

            // Check if this is an array - if so, pass address instead of variable
            int isArray = 0;
            if (sym && sym->kind == VAR_KIND && sym->info.var_info.type) {
                if (sym->info.var_info.type->kind == ARRAY_TYPE) {
                    isArray = 1;
                }
            }

            if (isArray) {
                // Array: check if parameter or local
                if (isParameterArrayName(idName)) {
                    // Parameter array: already contains address
                    pOperand varOp = newOperand(OP_VARIABLE, idName);
                    genInterCode(IR_ASSIGN, place, varOp);
                } else {
                    // Local array: need & to get address
                    pOperand addrOp = newOperand(OP_ADDRESS, idName);
                    genInterCode(IR_ASSIGN, place, addrOp);
                }
            } else {
                pOperand varOp = newOperand(OP_VARIABLE, idName);
                genInterCode(IR_ASSIGN, place, varOp);
            }
        } else if (strcmp(child->type, "INT") == 0) {
            int value = atoi(child->value);
            pOperand constOp = newOperand(OP_CONSTANT, value);
            genInterCode(IR_ASSIGN, place, constOp);
        }
        return;
    }

    if ((node->child_count == 2 && strcmp(node->children[0]->type, "NOT") == 0) ||
        (node->child_count == 3 && (strcmp(node->children[1]->type, "RELOP") == 0 ||
                                    strcmp(node->children[1]->type, "AND") == 0 ||
                                    strcmp(node->children[1]->type, "OR") == 0))) {
        pOperand labelTrue = newLabel();
        pOperand labelFalse = newLabel();
        pOperand zero = newOperand(OP_CONSTANT, 0);
        pOperand one = newOperand(OP_CONSTANT, 1);
        genInterCode(IR_ASSIGN, place, zero);
        translateCondNode(node, labelTrue, labelFalse);
        genInterCode(IR_LABEL, labelTrue);
        genInterCode(IR_ASSIGN, place, one);
        genInterCode(IR_LABEL, labelFalse);
        return;
    }

    if (node->child_count == 2 && strcmp(node->children[0]->type, "MINUS") == 0) {
        pOperand t1 = newTemp();
        translateExpNode(node->children[1], t1);
        pOperand zero = newOperand(OP_CONSTANT, 0);
        genInterCode(IR_SUB, place, zero, t1);
        /* t1 no longer needed after subtraction */
        releaseTemp(t1);
        return;
    }

    if (node->child_count == 3 && strcmp(node->children[0]->type, "LP") == 0 && strcmp(node->children[2]->type, "RP") == 0) {
        translateExpNode(node->children[1], place);
        return;
    }

    // Array access: handle multi-dimensional chains like a[i][j][k]
    if (node->child_count == 4 && strcmp(node->children[1]->type, "LB") == 0) {
        // Collect indices and find base ID
        Node *cur = node;
        // indices will be collected in reverse (from rightmost to leftmost)
        Node *indices[32];
        int idxCount = 0;
        while (cur && cur->child_count == 4 && strcmp(cur->children[1]->type, "LB") == 0) {
            indices[idxCount++] = cur->children[2];
            cur = cur->children[0];
            if (idxCount >= 32)
                break; // safety
        }
        // cur should now be the base (hopefully ID)
        if (!cur || cur->child_count != 1 || strcmp(cur->children[0]->type, "ID") != 0) {
            // fallback: treat as general expression
            read1DArray(node->children[0], node->children[2], place);
            return;
        }
        char *baseName = cur->children[0]->value;
        Symbol *sym = findSymbol(baseName);
        if (!sym || sym->kind != VAR_KIND) {
            // symbol not found or not variable: fallback
            read1DArray(node->children[0], node->children[2], place);
            return;
        }

        Type *t = sym->info.var_info.type;
        int n = idxCount;
        Node *idxNodes[32];
        for (int i = 0; i < n; i++) idxNodes[i] = indices[n - 1 - i];

        pOperand baseAddr;
        if (isParameterArrayName(baseName) || isPointerizedArray(baseName)) {
            // Parameter or pointerized array: variable contains address
            baseAddr = newOperand(OP_VARIABLE, baseName);
        } else {
            // Local array: need & to get address
            baseAddr = newOperand(OP_ADDRESS, baseName);
        }

        ArrayOffsetResult offset = computeArrayOffset(baseAddr, idxNodes, n, t);
        genInterCode(IR_READ_ADDR, place, offset.finalAddr);
        releaseTemp(offset.finalAddr);
        releaseTemp(offset.offsetSoFar);
        releaseTemp(baseAddr);
        return;
    }

    // Function calls: read() or write(arg) or other_func() or other_func(args)
    if (node->child_count >= 3 && strcmp(node->children[0]->type, "ID") == 0 && strcmp(node->children[1]->type, "LP") == 0) {
        char *funcName = node->children[0]->value;
        if (strcmp(funcName, "read") == 0) {
            genInterCode(IR_READ, place);
        } else if (strcmp(funcName, "write") == 0 && node->child_count == 4) {
            // node->children[2] is Args (which contains Exp)
            // Args can be: Exp COMMA Args (3 children) or just Exp (1 child)
            Node *argsNode = node->children[2];
            Node *firstExp = argsNode->child_count > 0 ? argsNode->children[0] : NULL;

            // Optimize: avoid temp for simple expressions in write
            pOperand argOp;
            if (firstExp && firstExp->child_count == 1 && strcmp(firstExp->children[0]->type, "ID") == 0) {
                argOp = newOperand(OP_VARIABLE, firstExp->children[0]->value);
            } else if (firstExp && firstExp->child_count == 1 && strcmp(firstExp->children[0]->type, "INT") == 0) {
                argOp = newOperand(OP_CONSTANT, atoi(firstExp->children[0]->value));
            } else {
                argOp = newTemp();
                if (firstExp)
                    translateExpNode(firstExp, argOp);
            }
            genInterCode(IR_WRITE, argOp);
            /* release temp used for write arg */
            releaseTemp(argOp);
        } else if (node->child_count == 3) {
            // Function call with no arguments
            pOperand funcOp = newOperand(OP_FUNCTION, funcName);
            genInterCode(IR_CALL, place, funcOp);
        } else {
            // Function call with arguments: ID LP Args RP
            // node->children[2] is Args
            translateArgsNode(node->children[2]);
            pOperand funcOp = newOperand(OP_FUNCTION, funcName);
            genInterCode(IR_CALL, place, funcOp);
        }
        return;
    }

    if (node->child_count == 3 &&
        (strcmp(node->children[1]->type, "PLUS") == 0 || strcmp(node->children[1]->type, "MINUS") == 0 ||
         strcmp(node->children[1]->type, "STAR") == 0 || strcmp(node->children[1]->type, "DIV") == 0)) {
        // Optimize: avoid creating temps for simple operands
        pOperand t1 = translateToOperand(node->children[0]);
        pOperand t2 = translateToOperand(node->children[2]);
        InterCodeKind kind = getBinaryOpKind(node->children[1]->type);
        genInterCode(kind, place, t1, t2);
        /* try to release t1 and t2 if they are temps */
        releaseTemp(t1);
        releaseTemp(t2);
        return;
    }

    // Handle simple ID (variable reference, including arrays when passed as parameter)

    // Handle integer constants
    if (node->child_count == 1 && strcmp(node->children[0]->type, "INT") == 0) {
        int val = atoi(node->children[0]->value);
        pOperand constOp = newOperand(OP_CONSTANT, val);
        genInterCode(IR_ASSIGN, place, constOp);
        return;
    }
}

// Process a single argument expression
// For simple variables/constants, directly generate ARG to avoid extra temp assignment
static void processArgument(Node *exp) {
    if (!exp)
        return;

    // For simple ID, check if it's an array
    if (exp->child_count == 1 && strcmp(exp->children[0]->type, "ID") == 0) {
        char *idName = exp->children[0]->value;
        Symbol *sym = findSymbol(idName);

        // Check if this is an array
        int isArray = 0;
        if (sym && sym->kind == VAR_KIND && sym->info.var_info.type) {
            if (sym->info.var_info.type->kind == ARRAY_TYPE) {
                isArray = 1;
            }
        }

        if (isArray) {
            // For arrays:
            // - If it's a parameter, pass it directly (it already contains address)
            // - If it's local, get its address with &
            if (isParameterArrayName(idName)) {
                // Parameter array: already contains address, pass directly
                pOperand var = newOperand(OP_VARIABLE, idName);
                genInterCode(IR_ARG, var);
            } else {
                // Local array: generate address
                pOperand addr = newOperand(OP_ADDRESS, idName);
                genInterCode(IR_ARG, addr);
            }
        } else {
            // For non-arrays, pass variable directly
            pOperand var = newOperand(OP_VARIABLE, idName);
            genInterCode(IR_ARG, var);
        }
        return;
    }

    // For simple INT, pass directly
    if (exp->child_count == 1 && strcmp(exp->children[0]->type, "INT") == 0) {
        int val = atoi(exp->children[0]->value);
        pOperand constOp = newOperand(OP_CONSTANT, val);
        genInterCode(IR_ARG, constOp);
        return;
    }

    // For complex expressions, use temp
    pOperand arg = newTemp();
    translateExpNode(exp, arg);
    genInterCode(IR_ARG, arg);
}

// Recursively process arguments from RIGHT to LEFT
// This helps avoid infinite recursion in nested function calls
static void translateArgsNodeRecursive(Node *node) {
    if (!node || node->child_count == 0)
        return;

    if (node->child_count == 1) {
        // Args : Exp (base case: single argument)
        processArgument(node->children[0]);
    } else if (node->child_count == 3) {
        // Args : Exp COMMA Args
        // Process right Args first (right to left)
        Node *rightArgs = node->children[2];
        translateArgsNodeRecursive(rightArgs);

        // Then process left Exp
        processArgument(node->children[0]);
    }
}

static void translateArgsNode(Node *node) {
    if (!node || node->child_count == 0)
        return;
    translateArgsNodeRecursive(node);
}

static void translateCondNode(Node *node, pOperand labelTrue, pOperand labelFalse) {
    if (!node)
        return;
    if (node->child_count == 2 && strcmp(node->children[0]->type, "NOT") == 0) {
        translateCondNode(node->children[1], labelFalse, labelTrue);
        return;
    }
    if (node->child_count == 3 && strcmp(node->children[1]->type, "RELOP") == 0) {
        pOperand t1 = translateToOperand(node->children[0]);
        pOperand t2 = translateToOperand(node->children[2]);
        pOperand relop = newOperand(OP_RELOP, node->children[1]->value);
        genInterCode(IR_IF_GOTO, t1, relop, t2, labelTrue);
        genInterCode(IR_GOTO, labelFalse);
        /* release temps used in condition evaluation */
        releaseTemp(t1);
        releaseTemp(t2);
        return;
    }
    if (node->child_count == 3 && strcmp(node->children[1]->type, "AND") == 0) {
        pOperand labelMid = newLabel();
        translateCondNode(node->children[0], labelMid, labelFalse);
        genInterCode(IR_LABEL, labelMid);
        translateCondNode(node->children[2], labelTrue, labelFalse);
        return;
    }
    if (node->child_count == 3 && strcmp(node->children[1]->type, "OR") == 0) {
        pOperand labelMid = newLabel();
        translateCondNode(node->children[0], labelTrue, labelMid);
        genInterCode(IR_LABEL, labelMid);
        translateCondNode(node->children[2], labelTrue, labelFalse);
        return;
    }
    pOperand t1 = newTemp();
    translateExpNode(node, t1);
    pOperand zero = newOperand(OP_CONSTANT, 0);
    pOperand relop = newOperand(OP_RELOP, "!=");
    genInterCode(IR_IF_GOTO, t1, relop, zero, labelTrue);
    genInterCode(IR_GOTO, labelFalse);
    releaseTemp(t1);
}

// Fast AST pre-scan: detect whether the AST contains uses of structure types
// as variables or function parameters. This scan only checks node types
// and shapes (no symbol table operations) and returns true if translation
// should be refused early to avoid expensive IR generation.
static bool astContainsStructUsage(Node *node) {
    if (!node)
        return false;
    // Check current node patterns
    // ExtDef: Specifier ExtDecList SEMI  -> global variable declaration
    if (strcmp(node->type, "ExtDef") == 0 && node->child_count >= 2) {
        Node *spec = node->children[0];
        if (spec && spec->child_count > 0 && strcmp(spec->children[0]->type, "StructSpecifier") == 0) {
            // If this ExtDef has a ExtDecList (variable declared), it's a struct variable
            if (node->child_count >= 2 && node->children[1] && strcmp(node->children[1]->type, "ExtDecList") == 0)
                return true;
        }
    }
    // Def: Specifier DecList SEMI  -> local variable declaration inside CompSt
    if (strcmp(node->type, "Def") == 0 && node->child_count >= 2) {
        Node *spec = node->children[0];
        if (spec && spec->child_count > 0 && strcmp(spec->children[0]->type, "StructSpecifier") == 0) {
            return true;
        }
    }
    // Param declaration inside VarList: ParamDec -> Specifier VarDec
    if (strcmp(node->type, "ParamDec") == 0 && node->child_count >= 1) {
        Node *spec = node->children[0];
        if (spec && spec->child_count > 0 && strcmp(spec->children[0]->type, "StructSpecifier") == 0)
            return true;
        // Also detect multi-dimensional array parameters (unsupported):
        if (node->child_count >= 2) {
            Node *varDec = node->children[1];
            int dims = 0;
            Node *cur = varDec;
            while (cur && cur->child_count == 4) { // VarDec -> VarDec LB INT RB
                dims++;
                cur = cur->children[0];
            }
            if (dims > 1) {
                // multi-dimensional array parameter found -> unsupported
                return true;
            }
        }
    }
    // Also handle VarList nodes where ParamDec may appear as child
    for (int i = 0; i < node->child_count; i++) {
        if (astContainsStructUsage(node->children[i]))
            return true;
    }
    return false;
}