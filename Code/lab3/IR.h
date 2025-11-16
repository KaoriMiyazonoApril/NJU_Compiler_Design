#ifndef INTER_H
#define INTER_H
#include "../../lab1/Node/Node.h"
#include "../../lab2/Type/Type.h"
#include "semantic.h"

typedef Node *pNode;
typedef Type *pType
typedef struct operand *pOperand;
typedef struct interCode *pInterCode;
typedef struct interCodes *pInterCodes;
typedef struct arg *pArg;
typedef struct argList *pArgList;
typedef struct interCodeList *pInterCodeList;//所要维护的双向链表


typedef enum {
    OP_VARIABLE,
    OP_CONSTANT,
    OP_ADDRESS,
    OP_LABEL,
    OP_FUNCTION,
    OP_RELOP
} OperandKind;

typedef enum {
    IR_LABEL, IR_FUNCTION, IR_ASSIGN, IR_ADD, IR_SUB, IR_MUL, IR_DIV,
    IR_GET_ADDR, IR_READ_ADDR, IR_WRITE_ADDR,
    IR_GOTO, IR_IF_GOTO, IR_RETURN, IR_DEC,
    IR_ARG, IR_CALL, IR_PARAM, IR_READ, IR_WRITE
} InterCodeKind;




typedef struct operand {
    OperandKind kind;
    union {
        int val;
        char *name;
    } u;
    bool isAddr //判断操作数是否是地址
} Operand;

typedef struct interCode {
    InterCodeKind kind;
    union {
        struct { pOperand op; } oneOp;
        struct { pOperand right, left; } assign;
        struct { pOperand result, op1, op2; } binOp;
        struct { pOperand x, relop, y, z; } ifGoto;
        struct { pOperand op; int size; } dec;
    } u;
} InterCode;


typedef struct interCodes {
    pInterCode code;
    struct interCodes *prev, *next;
} InterCodes;


typedef struct arg {
    pOperand op;
    struct arg *next;
} Arg;

typedef struct argList {
    pArg head;
    pArg cur;
} ArgList;

//双向链表
typedef struct interCodeList {
    pInterCodes head;
    pInterCodes cur;//当前链表末尾
    char *lastArrayName;//结构体数组，需要根据名字查表
    int tempVarNum;//临时变量编号
    int labelNum;//标签编号
} InterCodeList;


extern bool interError;
extern pInterCodeList interCodeList;


// Operand
pOperand newOperand(OperandKind kind, ...);
void deleteOperand(pOperand p);
void setOperand(pOperand p, OperandKind kind, void *val);
void printOp(FILE *fp, pOperand op);

// InterCode
pInterCode newInterCode(InterCodeKind kind, ...);
void deleteInterCode(pInterCode p);
void printInterCode(FILE *fp, pInterCodeList list);

// InterCodes
pInterCodes newInterCodes(pInterCode code);
void deleteInterCodes(pInterCodes p);


// InterCodeList
pInterCodeList newInterCodeList();
void deleteInterCodeList(pInterCodeList p);
void addInterCodes(pInterCodeList list, pInterCodes code);

// Arg
pArg newArg(pOperand op);
pArgList newArgList();
void deleteArg(pArg p);
void deleteArgList(pArgList p);
void addArg(pArgList list, pArg arg);

// Translate
pOperand newTemp();
pOperand newLabel();
int getSize(pType type);
void genInterCode(InterCodeKind kind, ...);
void translateExp(pNode node, pOperand place);
void translateArgs(pNode node, pArgList argList);
void translateCond(pNode node, pOperand labelTrue, pOperand labelFalse);
void translateVarDec(pNode node, pOperand place);
void translateDec(pNode node);
void translateDecList(pNode node);
void translateDef(pNode node);
void translateDefList(pNode node);
void translateCompSt(pNode node);
void translateStmt(pNode node);
void translateStmtList(pNode node);
void translateFunDec(pNode node);
void translateExtDef(pNode node);
void translateExtDefList(pNode node);
void generateIR(pNode root);
#endif
