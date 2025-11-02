#ifndef TYPE_H
#define TYPE_H
#include "../Symbol/Symbol.h"
#include "../../lab1/Node/Node.h"

typedef enum { INT_TYPE, FLOAT_TYPE, ARRAY_TYPE, STRUCTURE_TYPE } TypeKind;

typedef struct Type {
    TypeKind kind;
    Type *base;//基类
    int arrayDim;
    int *arraySizes;//分别记录每一维的大小,之后可能有用
    Symbol* structType;//如果是结构体,指向结构体符号表
}Type;

bool TypeEqual(Type *a, Type *b);
bool isLValue(Node *exp);          // stub, 语义分析时定义
Type* getType(Node *specifierNode); // stub, 从 Specifier 节点中解析类型
#endif