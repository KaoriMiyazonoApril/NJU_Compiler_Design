#include"Type.h"
extern int error_code;

bool TypeEqual(Type *a, Type *b) {
    if (a == NULL || b == NULL) {
        return false;
    }
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
        if (node->child_count >= 1 && node->children[0] && node->children[0]->value && strcmp(node->children[0]->value, "int") == 0)
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
            if (structName) {
                Symbol *exist = findSymbol(structName);
                if (!exist) {
                    insertSymbol(structSym);
                } else {
                    // leave error handling to caller; createStructSymbol may set error_code
                }
            }
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
                return NULL;
            }
            char *structName = tag->children[0]->value;
            Symbol *structSym = findSymbol(structName);
            if (!structSym || structSym->kind != STRUCT_KIND) {
                error_code = 17;
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