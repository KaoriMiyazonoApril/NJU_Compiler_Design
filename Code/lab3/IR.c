#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "IR.h"
#include "../../lab2/Type/Type.h "
#include "../../lab2/Symbol/Symbol.h"
#include "../../lab1/Node/Node.h"


boolean interError = FALSE;
pInterCodeList interCodeList;


//Operand
pOperand newOperand(OperandKind kind,...){
    pOperand p=(pOperand)malloc(sizeof(Operand));
    assert(p!=NULL);

    p->kind=kind;
    p->isAddr=false;
    va_list args;
    va_start(args,kind);

    if(kind==OP_CONSTANT){
        int v=va_arg(args,int);
        p->u.val=v;
    }else{
        //OP_RELOP
        char *name=va_arg(args,char*);
        p->u.name=strdup(name)
    }
    va_end(args);
    return p;
}

void deleteOperand(pOperand p){
    if(!p) return;

    if(p->kind!=OP_CONSTANT){
        if(p->u.name){
            free(p->u.name);
            p->u.name=NULL;
        }
    }
    free(p);
}

void setOperand(pOperand p, OperandKind kind, void *val){
    assert(p!=NULL);

    // 如果name有值，先释放。
    if (p->kind != OP_CONSTANT && p->u.name != NULL) {
        free(p->u.name);
        p->u.name = NULL;
    }


    p->kind=kind;
    if(kind==OP_CONSTANT){
        p->u.val=*(int*)val;
    }else{
        char *name =(char*)val;
        p->u.name=strdup(name);
    }
}

//Intercode
pInterCode newInterCode(InterCodeKind kind, ...) {
    pInterCode code = (pInterCode)malloc(sizeof(InterCode));
    assert(code != NULL);
    code->kind = kind;

    va_list args;
    va_start(args, kind);

    switch (kind) {
        //一元操作
        case IR_LABEL:
        case IR_FUNCTION:
        case IR_ARG:
        case IR_GOTO:
        case IR_PARAM:
        case IR_READ:
        case IR_WRITE:
        case IR_RETURN: {
            pOperand op = va_arg(args, pOperand);
            code->u.oneOp.op = op;
            break;
        }

        case IR_ASSIGN:
        case IR_CALL:
        case IR_GET_ADDR:
        case IR_READ_ADDR:
        case IR_WRITE_ADDR: {
            pOperand left = va_arg(args, pOperand);
            pOperand right = va_arg(args, pOperand);
            code->u.assign.left = left;
            code->u.assign.right = right;
            break;
        }

        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV: {
            pOperand res = va_arg(args, pOperand);
            pOperand op1 = va_arg(args, pOperand);
            pOperand op2 = va_arg(args, pOperand);
            code->u.binOp.result = res;
            code->u.binOp.op1 = op1;
            code->u.binOp.op2 = op2;
            break;
        }

        case IR_IF_GOTO: {
            pOperand x = va_arg(args, pOperand);
            pOperand relop = va_arg(args, pOperand);
            pOperand y = va_arg(args, pOperand);
            pOperand z = va_arg(args, pOperand);
            code->u.ifGoto.x = x;
            code->u.ifGoto.relop = relop;
            code->u.ifGoto.y = y;
            code->u.ifGoto.z = z;
            break;
        }

        case IR_DEC: {
            pOperand op = va_arg(args, pOperand);
            int size = va_arg(args, int);
            code->u.dec.op = op;
            code->u.dec.size = size;
            break;
        }

    }

    va_end(args);
    return code;
}

void deleteInterCode(pInterCode p) {
    if (!p) return;
    free(p);
}

//Intercodes
pInterCodes newInterCodes(pInterCode code) {
    pInterCodes node = (pInterCodes)malloc(sizeof(InterCodes));
    assert(node != NULL);

    node->code = code;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void deleteInterCodes(pInterCodes p) {
    if (!p) return;
    deleteInterCode(p->code);
    free(p);
}

//Intercodelist
pInterCodeList newInterCodeList() {
    pInterCodeList list = (pInterCodeList)malloc(sizeof(InterCodeList));
    assert(list != NULL);

    list->head = NULL;
    list->cur = NULL;
    list->labelNum = 1;
    list->tempVarNum = 1;
    list->lastArrayName = NULL;

    return list;
}

void deleteInterCodeList(pInterCodeList p) {
    if (!p) return;

    pInterCodes node = p->head;
    while (node) {
        pInterCodes tmp = node;
        node = node->next;
        deleteInterCodes(tmp);
    }

    if (p->lastArrayName) free(p->lastArrayName);
    free(p);
}

void addInterCodes(pInterCodeList list, pInterCodes code) {
    if (list->head == NULL) {
        list->head = code;
        list->cur = code;
    } else {
        list->cur->next = code;
        code->prev = list->cur;
        list->cur = code;
    }
}

//print
static void op_print(FILE *fp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    if (fp == NULL)
        vprintf(fmt, args);
    else
        vfprintf(fp, fmt, args);
    va_end(args);
}

void printOp(FILE* fp, pOperand op) {
    assert(op != NULL);
    switch (op->kind) {
        case OP_CONSTANT:
            op_print(fp, "#%d", op->u.val);
            break;
        case OP_VARIABLE:
        case OP_ADDRESS:
        case OP_LABEL:
        case OP_FUNCTION:
        case OP_RELOP:
            op_print(fp, "%s", op->u.name);
            break;
        default:
            op_print(fp, "<UNKNOWN_OP>");
            break;
    }
}


void printInterCode(FILE* fp, pInterCodeList interCodeList) {
    for (pInterCodes cur = interCodeList->head; cur != NULL; cur = cur->next) {
        assert(cur->code->kind >= 0 && cur->code->kind < 19);

        switch (cur->code->kind) {
            case IR_LABEL:
                op_print(fp, "LABEL ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, " :\n");
                break;
            case IR_FUNCTION:
                op_print(fp, "FUNCTION ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, " :\n");
                break;
            case IR_ASSIGN:
                printOp(fp, cur->code->u.assign.left);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.assign.right);
                op_print(fp, "\n");
                break;
            case IR_ADD:
                printOp(fp, cur->code->u.binOp.result);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.binOp.op1);
                op_print(fp, " + ");
                printOp(fp, cur->code->u.binOp.op2);
                op_print(fp, "\n");
                break;
            case IR_SUB:
                printOp(fp, cur->code->u.binOp.result);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.binOp.op1);
                op_print(fp, " - ");
                printOp(fp, cur->code->u.binOp.op2);
                op_print(fp, "\n");
                break;
            case IR_MUL:
                printOp(fp, cur->code->u.binOp.result);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.binOp.op1);
                op_print(fp, " * ");
                printOp(fp, cur->code->u.binOp.op2);
                op_print(fp, "\n");
                break;
            case IR_DIV:
                printOp(fp, cur->code->u.binOp.result);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.binOp.op1);
                op_print(fp, " / ");
                printOp(fp, cur->code->u.binOp.op2);
                op_print(fp, "\n");
                break;
            case IR_GET_ADDR:
                printOp(fp, cur->code->u.assign.left);
                op_print(fp, " := &");
                printOp(fp, cur->code->u.assign.right);
                op_print(fp, "\n");
                break;
            case IR_READ_ADDR:
                printOp(fp, cur->code->u.assign.left);
                op_print(fp, " := *");
                printOp(fp, cur->code->u.assign.right);
                op_print(fp, "\n");
                break;
            case IR_WRITE_ADDR:
                op_print(fp, "*");
                printOp(fp, cur->code->u.assign.left);
                op_print(fp, " := ");
                printOp(fp, cur->code->u.assign.right);
                op_print(fp, "\n");
                break;
            case IR_GOTO:
                op_print(fp, "GOTO ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n");
                break;
            case IR_IF_GOTO:
                op_print(fp, "IF ");
                printOp(fp, cur->code->u.ifGoto.x);
                op_print(fp, " ");
                printOp(fp, cur->code->u.ifGoto.relop);
                op_print(fp, " ");
                printOp(fp, cur->code->u.ifGoto.y);
                op_print(fp, " GOTO ");
                printOp(fp, cur->code->u.ifGoto.z);
                op_print(fp, "\n");
                break;
            case IR_RETURN:
                op_print(fp, "RETURN ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n");
                break;
            case IR_DEC:
                op_print(fp, "DEC ");
                printOp(fp, cur->code->u.dec.op);
                op_print(fp, " %d\n", cur->code->u.dec.size);
                break;
            case IR_ARG:
                op_print(fp, "ARG ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n");
                break;
            case IR_CALL:
                printOp(fp, cur->code->u.assign.left);
                op_print(fp, " := CALL ");
                printOp(fp, cur->code->u.assign.right);
                op_print(fp, "\n");
                break;
            case IR_PARAM:
                op_print(fp, "PARAM ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n"); break;
            case IR_READ:
                op_print(fp, "READ ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n"); break;
            case IR_WRITE:
                op_print(fp, "WRITE ");
                printOp(fp, cur->code->u.oneOp.op);
                op_print(fp, "\n"); break;
            default:
                op_print(fp, "<UNKNOWN_IR>\n"); break;
        }
    }
}
//args
pArg newArg(pOperand op) {
    pArg p = malloc(sizeof(Arg));
    assert(p != NULL);
    p->op = op;
    p->next = NULL;
    return p;
}
pArgList newArgList() {
    pArgList p = malloc(sizeof(ArgList));
    assert(p != NULL);
    p->head = NULL;
    p->cur = NULL;
    return p;
}
void deleteArg(pArg p) {
    assert(p != NULL);
    deleteOperand(p->op);
    free(p);
}

void deleteArgList(pArgList p) {
    assert(p != NULL);
    pArg q = p->head;
    while (q) {
        pArg temp = q;
        q = q->next;
        deleteArg(temp);
    }
    free(p);
}

void addArg(pArgList argList, pArg arg) {
    if (argList->head == NULL) {
        argList->head = arg;
        argList->cur = arg;
    } else {
        argList->cur->next = arg;
        argList->cur = arg;
    }
}

//translate
char *newString(char *src){
    if (src == NULL) return NULL;

    size_t length = strlen(src) + 1;
    char* p = (char*)malloc(length);
    assert(p != NULL);

    memcpy(p, src, length);
    return p;
}

pOperand newTemp() {
    char tName[32];
    sprintf(tName, "t%d", interCodeList->tempVarNum++);
    return newOperand(OP_VARIABLE, newString(tName));
}

pOperand newLabel() {
    char lName[32];
    sprintf(lName, "label%d", interCodeList->labelNum++);
    return newOperand(OP_LABEL, newString(lName));
}

int getSize(pType type){
    if(type==NULL) return 0;
    switch(type->kind){
        case INT_TYPE:
            return 4;
        case FLOAT_TYPE:
            return 4;
        case ARRY_TYPE:{
            int baseSize=getSize(type->base);
            int total=1;
            for(int i=0;i<type->arryDim;i++){
                total*=type->arrySizes[i];
            }
            return total*baseSize;
        }
        case STRUCTURE_TYPE:{
            int size=0;

            Symbol *sym=type->structType;
            if(!sym||sym->kind!=STRUCT_KIND)return 0;

            for(int i=0;i<sym->info.struct_info.symbolNum;i++){
                Symbol *fieldSym =sym->info.struct_info.symbol_list[i];
                Type *fieldType=fieldSym->info.var_info.type;
                size+=getSize(fieldType);
            }
            return size;
        }
    }
}

void generateIR(pNode root){

};

void genInterCode(InterCodeKind kind, ...){

}

void translateExtDefList(pNode node){

}
void translateExtDef(pNode node){

}

void translateCompSt(pNode node){

}

void translateDefList(pNode node){

}
void translateDef(pNode node){

}

void translateDecList(pNode node){

}
void translateDec(pNode node){

}

void translateVarDec(pNode node, pOperand place){

}
void translateStmtList(pNode node){

}

void translateStmt(pNode node){

}

void translateExp(pNode node,pOperand place){

}
void translateCond(pNode node,pOperand labelTrue,pOperand labelFalse){

}

void translateFunDec(pNode node){
    if(!node!!interErrot) return;

    //获取函数名
    char *funcName=node->childen[0]->value;
    //生成中间代码 FUNCTION f;
    genInterCode(IR_FUNCTION,newOperand(OP_FUNCTION,newString(funcName)));

    Symbol* sym =findSymbol(funcName);
    if(!sym||sym->kind!=FUNC_KIND){
        interError=true;
        printf("Internal error: function symbol not found.")
        return ;
    }

    //输出参数
    int argNum=sym->info.func_info.argNum;

    for(int i=0;i<argNum;i++){
        Symbol *arg=sym->info.func_info.arg_list[i];
        genInterCode(IR_PARAM, newOperand(OP_VARIABLE, newString(arg->name)));

    }


}

void translateArgs(Node* node, pArgList argList) {
    if (!node || interError) return;

    pOperand tempOp = newTemp();
    pArg argNode = newArg(tempOp);

    // 翻译 Exp → 把结果存到 tempOp
    translateExp(node->children[0], tempOp);

    // 检查该参数是否为数组参数 //
    if (tempOp->kind == OP_VARIABLE) {
        Symbol* sym = findSymbol(tempOp->u.name);
        if (sym && sym->kind == VAR_KIND
            && sym->info.var_info.type->kind == ARRAY_TYPE) {

            interError = true;
            printf("Cannot translate: Code containsvariables of "
                   "multi-dimensional array type or parameters of array "
                   "type.\n");
            return;
        }
    }

    
    addArg(argList, argNode);

    /* Args → Exp , Args */
    if (node->child_count == 3) {
        translateArgs(node->children[2], argList);
    }
}







