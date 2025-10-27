//author:dcy
#include "Node.h"
#include <stdio.h>
#include <string.h>

Node *root = NULL;
int lab1_sign=1;
int last_error_line=-1,bison_last_error_line=-1;//后面一个标志是语法错误

Node *newNodeN(char *type, char *value,int lineNo, int child_count, ...) {
    Node *t = malloc(sizeof(Node));
    t->child_count = child_count, t->lineNo = lineNo;
    

    t->type = malloc(strlen(type)+1);
    strcpy(t->type, type);

    t->value=malloc(strlen(value)+1);
    strcpy(t->value, value);

    if (child_count > 0) {
        t->children = (Node **)(malloc(child_count * sizeof(Node *)));
    } else {
        t->children=NULL;
    }

    va_list args;
    va_start(args, child_count); //开始取参数，从 child_count 之后的第一个变参起

    for (int i = 0; i < child_count; i++) {
        t->children[i] = va_arg(args, Node *); //每个参数都是 Node*
    }
    va_end(args);
    return t;
}

void printTree(Node *node, int depth) {
    if (node == NULL)
        return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    if (node->child_count > 0) {
        printf("%s (%d)\n", node->type, node->lineNo);

        for (int i = 0; i < node->child_count; i++) {
            printTree(node->children[i], depth+1);
        }
    } //非终结符

    else {
        printf("%s", node->type);
        if (strcmp(node->value, "") != 0) {
            printf(": %s",node->value);
        }
        printf("\n");
    } //终结符
}

void freeTree(Node *node) {
    if (node == NULL)
        return;

    if (node->child_count > 0) {
        for (int i = 0; i < node->child_count; i++) {
            freeTree(node->children[i]);
        }
        free(node->children);
    }
    if (node->type != NULL)
        free(node->type);

    if (node->value != NULL)
        free(node->value);

    free(node);
}
