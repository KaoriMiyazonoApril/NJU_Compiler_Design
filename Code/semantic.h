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

// 前向声明
void traverseProgram(Node *node);
void traverseExtDefList(Node *node);
void traverseExtDef(Node *node);
void traverseExtDecList(Node *node, Type *baseType);
void handleFuncDef(Node *funDec, Type *retType, Node *compSt);
void traverseCompSt(Node *node, Type *retType);
void traverseDefList(Node *node);
void traverseDef(Node *node);
void traverseDecList(Node *node, Type *baseType);
void traverseStmtList(Node *node, Type *retType);
void traverseStmt(Node *node, Type *retType);
Type *checkExp(Node *exp);
Type *handleStructSpecifier(Node *node);
void insertFuncParams(Node *funDec);
bool checkFuncCall(Symbol *funcSym, Node *argsNode, int line);
Symbol *getStructField(Symbol *structSym, char *fieldName);
#endif
