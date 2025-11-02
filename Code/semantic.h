#ifndef SEMANTIC_H
#define SEMANTIC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab1/Node/Node.h"
#include "lab2/Symbol/Symbol.h"

/// ==================== 对外接口 ====================

/**
 * 对语法树进行语义分析
 * @param root 语法树根节点
 */
void semanticAnalysis(Node *root);

/// ==================== 内部函数声明（可选暴露） ====================
// 如果你希望把这些函数仅限semantic.c内部使用，可以在.c中用static修饰，这里可以不写
void traverseProgram(Node *node);
void traverseExtDefList(Node *node);
void traverseExtDef(Node *node);
void traverseExtDecList(Node *node, Type type);
void handleFunctionDef(Node *funDec, Type returnType, Node *compSt);
void traverseCompSt(Node *node, Type returnType);
void traverseDefList(Node *node);
void traverseDef(Node *node);
void traverseDecList(Node *node, Type type);
void traverseStmtList(Node *node, Type returnType);
void traverseStmt(Node *node, Type returnType);
Type checkExpression(Node *exp);
Type handleStructDef(Node *node);
Type checkStructVariable(Node *varDec, Type baseType);
void semanticError(int type, int line, const char *msg);

#endif
