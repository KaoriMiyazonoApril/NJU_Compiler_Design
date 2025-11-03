#include "Symbol.h"
#include "../Type/Type.h"

enum {stackSize = 15};
Symbol * stak[stackSize];
int top = 0; // 使用栈+链表方式存储symbol(符号)

int error_code = 0;//作为返回值在遍历树的过程中记得每次都要清零

// 感觉结构体的定义和具体实例上来说还是有点问题
//enter 仅在进入函数体(声明和结构体都不能)或块时调用
void enterScope() {
    top++;
    if (top >= stackSize) {
        top--;
        exit(-5);//嵌套层数过多爆栈,需要调整栈的size
    }
        
}

void exitScope() {
    if (top < 0) {
        exit(-4); // 误用了exit函数,在不在括号的情况下弹出
    }
    // freeSymbolStack(top);
    stak[top]=NULL;
    top--;
    if (top < 0) {
        exit(-4); // 误用了exit函数,在不在括号的情况下弹出
    }
}

//外部不要释放type,且对每一个对象都要创建一个type指针,最后交给symbol中实现的函数统一释放
Symbol *createVariableSymbol(char *name, Type* type, int line) {
    Symbol *t = malloc(sizeof(Symbol));

    t->kind=VAR_KIND;
    t->name = malloc(strlen(name) + 1);
    strcpy(t->name, name);
    t->lineno = line;
    t->info.var_info.type=type;
    

    return t;
}

//只算函数声明,如果是函数定义,应该直接enterscope,然后把参数插进去
Symbol *createFunctionSymbol(char *name, Type* return_type, int line, int argNum, Symbol** argList) {
    Symbol *t = malloc(sizeof(Symbol));

    t->kind = FUNC_KIND;
    t->name = malloc(strlen(name) + 1);
    strcpy(t->name, name);
    t->lineno = line;

    t->info.func_info.return_type = return_type;
    t->info.func_info.isDefined = false;
    
    t->info.func_info.argNum = argNum;
    if (argNum > 0) {
        t->info.func_info.arg_list = malloc(argNum * sizeof(Symbol *));
        for (int i = 0; i < argNum; i++) {
            t->info.func_info.arg_list[i] = argList[i];
            for (int j = 0; j < i; j++) {
                if (strcmp(t->info.func_info.arg_list[j]->name, t->info.func_info.arg_list[i]->name) == 0) {
                    error_code = 3;
                    return NULL; // 保证函数声明中参数名不重复
                }
            }
        }
    }

    return t;
}

Symbol *createStructSymbol(char *name, int line, int symbolNum, Symbol** symbolList) {

    Symbol *t = malloc(sizeof(Symbol));

    t->kind = STRUCT_KIND;
    t->name = malloc(strlen(name) + 1);
    strcpy(t->name, name);
    t->lineno = line;

    t->info.struct_info.symbolNum = symbolNum;
    if (symbolNum > 0) {
        t->info.struct_info.symbol_list = malloc(symbolNum * sizeof(Symbol *));
        for (int i = 0; i < symbolNum; i++) {
            t->info.struct_info.symbol_list[i] = symbolList[i];
            // 检查名字重复
            for (int j = 0; j < i; j++) {
                if (strcmp(t->info.struct_info.symbol_list[i]->name, t->info.struct_info.symbol_list[j]->name) == 0) {
                    error_code = 15;
                    return NULL;
                }
            }
        }
    }

    return t;
}

void freeSymbolStack(int tp) {//free 第tp层的内存
    if (tp < 0 || stak[tp]==NULL)
        return;

    Symbol *tofree = stak[tp];
    while (tofree != NULL) {
        Symbol *next = tofree->next;
        freeSymbol(tofree);
        tofree=next;
    }
    stak[tp]=NULL;
}

void freeSymbol(Symbol *tofree) {
    if (tofree == NULL)
        return;

    free(tofree->name);

    if (tofree->kind == VAR_KIND) {
        free(tofree->info.var_info.type);
    }
    else if (tofree->kind == FUNC_KIND) {
        free(tofree->info.func_info.return_type);
        for (int i = 0; i < tofree->info.func_info.argNum; i++) {
            freeSymbol(tofree->info.func_info.arg_list[i]);
        }
        free(tofree->info.func_info.arg_list);
    }
    else if (tofree->kind == STRUCT_KIND) {
        for (int i = 0; i < tofree->info.struct_info.symbolNum; i++) {
            freeSymbol(tofree->info.struct_info.symbol_list[i]);
        }
        free(tofree->info.struct_info.symbol_list);
    }

    free(tofree);
}

Symbol *findSymbol(char *name) {
    // 因为insert时候保证了同一层只有一个,所以可以直接找
    Symbol *ans = NULL;
    int tp=top;

    while (tp >= 0) {
        Symbol *temp = stak[tp];
        while (temp != NULL) {
            if (strcmp(name, temp->name) == 0) {
                ans = temp;
                break;
            }
            temp=temp->next;
        }
        tp--;
    }

    return ans;
}

void insertSymbol(Symbol *sym) {
    Symbol *t = stak[top];
    bool func_redefine_sign = false;
    error_code = 0;
    
    while (t != NULL) {
        if (strcmp(t->name, sym->name) == 0) {
            if (sym->kind==VAR_KIND) {
                error_code = 3; // 变量的重定义
                return;
            }
            else if (sym->kind == FUNC_KIND && t->kind == FUNC_KIND) { // 函数允许相同时候的重定义
                func_redefine_sign=true;
                if (sym->info.func_info.argNum != t->info.func_info.argNum) {
                    error_code = 19;
                    return;
                }

                for (int i = 0; i < sym->info.func_info.argNum; i++) {
                    Type *a = sym->info.func_info.arg_list[i]->info.var_info.type;
                    Type *b = t->info.func_info.arg_list[i]->info.var_info.type;
                    if (TypeEqual(a, b) != 0) {//类型为false
                        error_code = 19;
                        return;
                    }
                }
            } else if (sym->kind == FUNC_KIND) {
                error_code = 3; // 不确定先定义了变量,后定义函数的error_code;
                return;
            } else if (sym->kind == STRUCT_KIND) {
                error_code = 16;
                return;
            }
        }
        t=t->next;
    }
    if (func_redefine_sign == false) {
        t = stak[top];
        sym->next = t;
        stak[top] = sym;
    }
}

bool isInStruct(Symbol *sym, char *name) {
    if (sym->kind != STRUCT_KIND) {
        exit(-114); // 没有传入类型,而是传入了实例
    }

    for (int i = 0; i < sym->info.struct_info.symbolNum; i++) {
        if (strcmp(sym->info.struct_info.symbol_list[i]->name, name)==0) {
            return true;
        }
    }
    error_code = 14;
    return false;
}