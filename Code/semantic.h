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
 * @return 是否成功翻译（true表示成功，false表示不支持该代码）
 */
bool semanticAnalysis(Node *root);

/**
 * 释放语义分析的所有资源
 */
void freeSemanticResource(void);

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

// 添加printError函数的前向声明
void printError(int type, int line, const char *msg);
#endif