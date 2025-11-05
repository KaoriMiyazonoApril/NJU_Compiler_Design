#include"Type.h"
#include"../../semantic.h"
extern int error_code;

bool TypeEqual(Type *a, Type *b) {
    if(a==NULL&&b==NULL)
        return true;
    if (a == NULL || b == NULL) {
        return false;
    }
    //printf("a->kind = %d, b->kind = %d\n", a->kind, b->kind);
    if (a->kind != b->kind) {
        return false;
    }
    switch (a->kind) {
        case INT_TYPE:
        case FLOAT_TYPE:
            return true;
        case ARRAY_TYPE:
            return TypeEqual(a->base, b->base) && (a->arrayDim == b->arrayDim);
        case STRUCTURE_TYPE:
            // 名等价：仅当两者引用同一结构体符号时相等（包括同名同符号）。
            // 对匿名结构体而言，不同定义即使结构相同也不相等。
            return a->structType == b->structType;
        default:
            return false;
    }
}

bool isLValue(Node *n) {
    if (!n)
        return false;
    if (strcmp(n->type, "Exp") == 0 && n->child_count >= 1) {
        Node *c = n->children[0];
        if (c && strcmp(c->type, "ID") == 0 && n->child_count == 1)
            return true;
        if (n->child_count == 4 && strcmp(n->children[1]->type, "LB") == 0)
            return true;
        if (n->child_count == 3 && strcmp(n->children[1]->type, "DOT") == 0)
            return true;
    }
    return false;
}

Type *getType(Node *specifier) {
    if (!specifier) return NULL;

    // If passed a "Specifier" node, its child is either TYPE or StructSpecifier
    Node *node = specifier;
    if (strcmp(node->type, "Specifier") == 0 && node->child_count >= 1) {
        node = node->children[0];
    }
    
    if (strcmp(node->type, "TYPE") == 0) {
        Type *t = malloc(sizeof(Type));
        // 修复：直接检查node->value而不是node->children[0]->value
        if (node->value && strcmp(node->value, "int") == 0)
            t->kind = INT_TYPE;
        else
            t->kind = FLOAT_TYPE;
        t->base = NULL;
        t->arrayDim = 0;
        t->arraySizes = NULL;
        t->structType = NULL;
        return t;
    }

    if (strcmp(node->type, "StructSpecifier") == 0) {
        // node forms: STRUCT OptTag LC DefList RC  (definition)
        // or STRUCT Tag (reference)
        if (node->child_count == 5) {
            Node *optTag = node->children[1];
            Node *defList = node->children[3];
            char *structName = NULL;
            if (optTag && optTag->child_count == 1)
                structName = optTag->children[0]->value;

            // collect members
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
                // specifier for field
                Node *fieldSpec = def->children[0];
                Node *decList = def->children[1];
                Node *curDecList = decList;
                while (curDecList && curDecList->child_count > 0) {
                    Node *dec = curDecList->children[0];
                    Node *varDec = dec->children[0];
                    // field name node
                    Node *idNode = varDec->children[0];
                    char *fieldName = idNode->value;
                    int line = idNode->lineNo;
                    // base type for field
                    Type *baseType = getType(fieldSpec);
                    Type *finalType = baseType;
                    Node *curVar = varDec;
                    while (curVar && curVar->child_count == 4) {
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

            Symbol *structSym = createStructSymbol(structName ? structName : "", node->lineNo, memberCount, members);
            if (structSym == NULL) {
                // 释放已分配的members数组内存
                if (members) free(members);
                return NULL;
            }
            //if (structName) {
                //Symbol *exist = findSymbol(structName);
                //if (!exist) {
                 //   insertSymbol(structSym);
                //} else {
                    // leave error handling to caller; createStructSymbol may set error_code
                //}
            //}
            Type *ret = malloc(sizeof(Type));
            ret->kind = STRUCTURE_TYPE;
            ret->structType = structSym;
            ret->base = NULL;
            ret->arrayDim = 0;
            ret->arraySizes = NULL;
            return ret;
        }
        // reference: STRUCT Tag
        else if (node->child_count == 2) {
            Node *tag = node->children[1];
            if (!tag || tag->child_count == 0) {
                error_code = 17; // undefined struct
                printError(17, node->lineNo, "Undefined struct used");
                return NULL;
            }
            char *structName = tag->children[0]->value;
            Symbol *structSym = findSymbol(structName);
            if (!structSym || structSym->kind != STRUCT_KIND) {
                error_code = 17;
                printError(17, node->lineNo, "Undefined struct used");
                return NULL;
            }
            Type *ret = malloc(sizeof(Type));
            ret->kind = STRUCTURE_TYPE;
            ret->structType = structSym;
            ret->base = NULL;
            ret->arrayDim = 0;
            ret->arraySizes = NULL;
            return ret;
        }
    }
    return NULL;
}

bool StructEqual(Symbol *a, Symbol *b) {
    if(a->kind!=STRUCT_KIND||b->kind!=STRUCT_KIND)
        exit(-79);//找错了

    if(a->info.struct_info.symbolNum != b->info.struct_info.symbolNum)
        return false;
    for (int i = 0; i < a->info.struct_info.symbolNum; i++) {
        if(a->info.struct_info.symbol_list[i]->kind!= b->info.struct_info.symbol_list[i]->kind)
            return false;
        switch (a->info.struct_info.symbol_list[i]->kind) {
            case VAR_KIND: {
                Type *typeA = a->info.struct_info.symbol_list[i]->info.var_info.type;
                Type *typeB = b->info.struct_info.symbol_list[i]->info.var_info.type;
                if (!TypeEqual(typeA, typeB))
                    return false;
                break;
            }
            case STRUCT_KIND:
                if (!StructEqual(a->info.struct_info.symbol_list[i], b->info.struct_info.symbol_list[i]))
                    return false;
                break;
            default:
                exit(-80); // 结构体内出现非变量成员
        }
    }
    return true;
}