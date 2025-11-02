#include"Type.h"
#include <cstdlib>
#include <cstring>
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

// 本函数为 int,float,struct和数组类型生成type
Type *getType(Node *specifier) {
    Type * ans=NULL;
    if (!specifier)
        return NULL;
    if (specifier->child_count == 0)
        return NULL;

    Node *first = specifier->children[0];

    if (strcmp(specifier->type, "TYPE") == 0) {
        ans = malloc(sizeof(Type));
        if (first->value && strcmp(first->value, "int") == 0)
            return ans->kind = INT_TYPE, ans;
        else
            return ans->kind = FLOAT_TYPE, ans;
    }

    else if (strcmp(first->type, "StructSpecifier") == 0) {
        //结构体类型
        ans = malloc(sizeof(Type));
        ans->kind = STRUCTURE_TYPE;
        //todo:在遍历的时候把type的指针指向createStructSymbol返回的指针
        return ans;
    }
    //数组类型
    else if (strcmp(specifier->type,"ParamDec")==0) {
        ans = malloc(sizeof(Type));
        ans->kind=ARRAY_TYPE;
        ans->base = getType(specifier->children[0]);
        int arrayDim = 0;
        Node *tv = first;
        
        while (tv->child_count == 4) {
            arrayDim++;
            tv = tv->children[0];
        }
        ans->arrayDim = arrayDim;
        ans->arraySizes = malloc(arrayDim * sizeof(int));
        tv = first;

        while(tv->child_count == 4) {
            int size = atoi(tv->children[2]->value);
            ans->arraySizes[--arrayDim] = size;
            tv = tv->children[0];
        }
        
    }
    return ans;
}