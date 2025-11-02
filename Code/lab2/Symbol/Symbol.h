#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

typedef struct Type Type;

typedef struct var {
    Type *type;

} var;

typedef struct Symbol Symbol; // 提前告诉编译器 "有一个类型 Symbol 存在"
typedef struct func {
    Type *return_type;
    bool isDefined;//是否已经被定义了,不能重复定义
    int argNum;
    Symbol **arg_list;

} func;

typedef struct struc {
    int symbolNum;
    Symbol **symbol_list;
} struc;

typedef enum { VAR_KIND,
               FUNC_KIND,
               STRUCT_KIND } SymbolKind;

typedef struct Symbol {
    SymbolKind kind;
    char *name;
    Symbol *next;
    int lineno;

    union {
        var var_info;
        func func_info;
        struc struct_info;
    } info;

} Symbol; // 所有符号定义形成一张表

void enterScope();
void exitScope();
Symbol *createVariableSymbol(char *name, Type *type, int line);
Symbol *createFunctionSymbol(char *name, Type *return_type, int line, int argNum, Symbol **argList);
Symbol *createStructSymbol(char *name, int line, int symbolNum, Symbol **symbolList);
void freeSymbolStack(int tp);
void freeSymbol(Symbol *tofree);

Symbol *findSymbol(char *name);
void insertSymbol(Symbol *sym);

bool isInStruct(Symbol *sym, char *name); // a.x的x是否在a对应的类里,请传入a对应的类指针
#endif