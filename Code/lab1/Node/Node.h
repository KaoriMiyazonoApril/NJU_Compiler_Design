//author:dcy lab1定义的语法节点
#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include<string.h>
typedef struct Node {
    char* type;//类型
    char *value; // 值
    int lineNo;//在第几行
    struct Node** children;//按照子单元数量malloc出的数组
    int child_count;
} Node;
Node *newNodeN(char *type, char* value,int lineNo, int child_count, ...);//新建一个节点,把子节点append上去并返回指针
void printTree(Node *node, int depth);//lab 1功能
void freeTree(Node *node);//释放所有节点

#endif