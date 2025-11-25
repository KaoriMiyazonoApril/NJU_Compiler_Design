#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "IR.h"

bool interError = false;
pInterCodeList interCodeList = NULL;

static char *dupName(const char *src) {
    if (!src)
        return NULL;
    size_t len = strlen(src);
    char *dst = (char *)malloc(len + 1);
    if (!dst)
        return NULL;
    memcpy(dst, src, len + 1);
    return dst;
}

// ==================== Operand ====================

pOperand newOperand(OperandKind kind, ...) {
    pOperand op = (pOperand)malloc(sizeof(Operand));
    if (!op)
        return NULL;
    op->kind = kind;
    op->isAddr = false;

    va_list args;
    va_start(args, kind);
    switch (kind) {
    case OP_CONSTANT:
        op->u.val = va_arg(args, int);
        break;
    default: {
        char *name = va_arg(args, char *);
        op->u.name = dupName(name);
        break;
    }
    }
    va_end(args);
    return op;
}

void deleteOperand(pOperand p) {
    if (!p)
        return;
    if (p->kind != OP_CONSTANT && p->u.name) {
        free(p->u.name);
    }
    free(p);
}

void printOp(FILE *fp, pOperand op) {
    if (!op || !fp)
        return;
    switch (op->kind) {
    case OP_VARIABLE:
        fprintf(fp, "%s", op->u.name);
        break;
    case OP_CONSTANT:
        fprintf(fp, "#%d", op->u.val);
        break;
    case OP_ADDRESS:
        fprintf(fp, "&%s", op->u.name);
        break;
    case OP_LABEL:
    case OP_FUNCTION:
    case OP_RELOP:
        fprintf(fp, "%s", op->u.name);
        break;
    default:
        fprintf(fp, "%s", op->u.name);
        break;
    }
}

// ==================== InterCode ====================

pInterCode newInterCode(InterCodeKind kind, ...) {
    pInterCode code = (pInterCode)malloc(sizeof(InterCode));
    if (!code)
        return NULL;
    code->kind = kind;

    va_list args;
    va_start(args, kind);
    switch (kind) {
    case IR_LABEL:
    case IR_FUNCTION:
    case IR_RETURN:
    case IR_GOTO:
    case IR_READ:
    case IR_WRITE:
    case IR_PARAM:
    case IR_ARG: {
        pOperand op = va_arg(args, pOperand);
        code->u.oneOp.op = op;
        break;
    }
    case IR_ASSIGN:
    case IR_GET_ADDR:
    case IR_READ_ADDR:
    case IR_WRITE_ADDR:
    case IR_CALL: {
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
        pOperand result = va_arg(args, pOperand);
        pOperand op1 = va_arg(args, pOperand);
        pOperand op2 = va_arg(args, pOperand);
        code->u.binOp.result = result;
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

void deleteInterCode(pInterCode code) {
    if (!code)
        return;
    switch (code->kind) {
    case IR_LABEL:
    case IR_FUNCTION:
    case IR_RETURN:
    case IR_GOTO:
    case IR_READ:
    case IR_WRITE:
    case IR_PARAM:
    case IR_ARG:
        deleteOperand(code->u.oneOp.op);
        break;
    case IR_ASSIGN:
    case IR_GET_ADDR:
    case IR_READ_ADDR:
    case IR_WRITE_ADDR:
    case IR_CALL:
        deleteOperand(code->u.assign.left);
        deleteOperand(code->u.assign.right);
        break;
    case IR_ADD:
    case IR_SUB:
    case IR_MUL:
    case IR_DIV:
        deleteOperand(code->u.binOp.result);
        deleteOperand(code->u.binOp.op1);
        deleteOperand(code->u.binOp.op2);
        break;
    case IR_IF_GOTO:
        deleteOperand(code->u.ifGoto.x);
        deleteOperand(code->u.ifGoto.relop);
        deleteOperand(code->u.ifGoto.y);
        deleteOperand(code->u.ifGoto.z);
        break;
    case IR_DEC:
        deleteOperand(code->u.dec.op);
        break;
    }
    free(code);
}

// ==================== InterCodes List ====================

pInterCodes newInterCodes(pInterCode code) {
    if (!code)
        return NULL;
    pInterCodes node = (pInterCodes)malloc(sizeof(InterCodes));
    if (!node)
        return NULL;
    node->code = code;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void deleteInterCodes(pInterCodes node) {
    if (!node)
        return;
    deleteInterCode(node->code);
    free(node);
}

pInterCodeList newInterCodeList() {
    pInterCodeList list = (pInterCodeList)malloc(sizeof(InterCodeList));
    if (!list)
        return NULL;
    list->head = NULL;
    list->cur = NULL;
    list->lastArrayName = NULL;
    list->tempVarNum = 1;
    list->labelNum = 1;
    list->freeTempTop = 0;
    return list;
}

void deleteInterCodeList(pInterCodeList list) {
    if (!list)
        return;
    pInterCodes cur = list->head;
    while (cur) {
        pInterCodes next = cur->next;
        deleteInterCodes(cur);
        cur = next;
    }
    if (list->lastArrayName)
        free(list->lastArrayName);
    free(list);
}

void addInterCodes(pInterCodeList list, pInterCodes node) {
    if (!list || !node)
        return;
    if (!list->head) {
        list->head = node;
        list->cur = node;
    } else {
        list->cur->next = node;
        node->prev = list->cur;
        list->cur = node;
    }
}

// ==================== Arg List ====================

pArg newArg(pOperand op) {
    pArg arg = (pArg)malloc(sizeof(Arg));
    if (!arg)
        return NULL;
    arg->op = op;
    arg->next = NULL;
    return arg;
}

pArgList newArgList() {
    pArgList list = (pArgList)malloc(sizeof(ArgList));
    if (!list)
        return NULL;
    list->head = NULL;
    list->cur = NULL;
    return list;
}

void deleteArg(pArg arg) {
    if (!arg)
        return;
    deleteOperand(arg->op);
    free(arg);
}

void deleteArgList(pArgList list) {
    if (!list)
        return;
    pArg cur = list->head;
    while (cur) {
        pArg next = cur->next;
        deleteArg(cur);
        cur = next;
    }
    free(list);
}

void addArg(pArgList list, pArg arg) {
    if (!list || !arg)
        return;
    arg->next = list->head;
    list->head = arg;
    if (!list->cur)
        list->cur = arg;
}

// ==================== Helpers ====================

static pOperand newNamedOperand(const char *prefix, int index) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "%s%d", prefix, index);
    return newOperand(OP_VARIABLE, buffer);
}

pOperand newTemp() {
    if (!interCodeList)
        interCodeList = newInterCodeList();
    return newNamedOperand("t", interCodeList->tempVarNum++);
}

/* For safety, releaseTemp is currently a no-op to avoid reusing
   textual temporary names while previously-generated IR still
   references them. Proper reuse requires liveness analysis; keep
   this function as a placeholder. */
void releaseTemp(pOperand op) {
    (void)op;
}

pOperand newLabel() {
    if (!interCodeList)
        interCodeList = newInterCodeList();
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "label%d", interCodeList->labelNum++);
    return newOperand(OP_LABEL, buffer);
}

int getSize(pType type) {
    if (!type)
        return 4;
    switch (type->kind) {
    case INT_TYPE:
    case FLOAT_TYPE:
        return 4;
    case ARRAY_TYPE:
        if (type->arrayDim > 0 && type->arraySizes)
            return type->arraySizes[0] * getSize(type->base);
        return getSize(type->base);
    case STRUCTURE_TYPE: {
        if (!type->structType)
            return 0;
        int total = 0;
        int count = type->structType->info.struct_info.symbolNum;
        for (int i = 0; i < count; i++) {
            Symbol *field = type->structType->info.struct_info.symbol_list[i];
            if (field && field->info.var_info.type)
                total += getSize(field->info.var_info.type);
        }
        return total;
    }
    default:
        return 4;
    }
}

// ==================== IR Printing ====================

void printInterCode(FILE *fp, pInterCodeList list) {
    if (!fp || !list)
        return;
    
    for (pInterCodes cur = list->head; cur != NULL; cur = cur->next) {
        pInterCode code = cur->code;
        
        switch (code->kind) {
        case IR_LABEL:
            fprintf(fp, "LABEL ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, " :\n");
            break;
        case IR_FUNCTION:
            fprintf(fp, "FUNCTION ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, " :\n");
            break;
        case IR_ASSIGN:
            printOp(fp, code->u.assign.left);
            fprintf(fp, " := ");
            printOp(fp, code->u.assign.right);
            fprintf(fp, "\n");
            break;
        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV: {
            printOp(fp, code->u.binOp.result);
            fprintf(fp, " := ");
            printOp(fp, code->u.binOp.op1);
            const char *op = (code->kind == IR_ADD) ? " + " :
                             (code->kind == IR_SUB) ? " - " :
                             (code->kind == IR_MUL) ? " * " : " / ";
            fprintf(fp, "%s", op);
            printOp(fp, code->u.binOp.op2);
            fprintf(fp, "\n");
            break;
        }
        case IR_GET_ADDR:
            printOp(fp, code->u.assign.left);
            fprintf(fp, " := &");
            printOp(fp, code->u.assign.right);
            fprintf(fp, "\n");
            break;
        case IR_READ_ADDR:
            printOp(fp, code->u.assign.left);
            fprintf(fp, " := *");
            printOp(fp, code->u.assign.right);
            fprintf(fp, "\n");
            break;
        case IR_WRITE_ADDR:
            fprintf(fp, "*");
            printOp(fp, code->u.assign.left);
            fprintf(fp, " := ");
            printOp(fp, code->u.assign.right);
            fprintf(fp, "\n");
            break;
        case IR_GOTO:
            fprintf(fp, "GOTO ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        case IR_IF_GOTO:
            fprintf(fp, "IF ");
            printOp(fp, code->u.ifGoto.x);
            fprintf(fp, " ");
            printOp(fp, code->u.ifGoto.relop);
            fprintf(fp, " ");
            printOp(fp, code->u.ifGoto.y);
            fprintf(fp, " GOTO ");
            printOp(fp, code->u.ifGoto.z);
            fprintf(fp, "\n");
            break;
        case IR_RETURN:
            fprintf(fp, "RETURN ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        case IR_DEC:
            fprintf(fp, "DEC ");
            printOp(fp, code->u.dec.op);
            fprintf(fp, " %d\n", code->u.dec.size);
            break;
        case IR_ARG:
            fprintf(fp, "ARG ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        case IR_CALL:
            printOp(fp, code->u.assign.left);
            fprintf(fp, " := CALL ");
            printOp(fp, code->u.assign.right);
            fprintf(fp, "\n");
            break;
        case IR_PARAM:
            fprintf(fp, "PARAM ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        case IR_READ:
            fprintf(fp, "READ ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        case IR_WRITE:
            fprintf(fp, "WRITE ");
            printOp(fp, code->u.oneOp.op);
            fprintf(fp, "\n");
            break;
        default:
            break;
        }
    }
}


// ==================== IR Generation Helpers ====================

void genInterCode(InterCodeKind kind, ...) {
    if (interError)
        return;
    if (!interCodeList)
        interCodeList = newInterCodeList();

    va_list args;
    va_start(args, kind);
    pInterCode code = NULL;

    switch (kind) {
    case IR_LABEL:
    case IR_FUNCTION:
    case IR_RETURN:
    case IR_GOTO:
    case IR_READ:
    case IR_WRITE:
    case IR_PARAM:
    case IR_ARG: {
        pOperand op = va_arg(args, pOperand);
        code = newInterCode(kind, op);
        break;
    }
    case IR_ASSIGN:
    case IR_GET_ADDR:
    case IR_READ_ADDR:
    case IR_WRITE_ADDR:
    case IR_CALL: {
        pOperand left = va_arg(args, pOperand);
        pOperand right = va_arg(args, pOperand);
        code = newInterCode(kind, left, right);
        break;
    }
    case IR_ADD:
    case IR_SUB:
    case IR_MUL:
    case IR_DIV: {
        pOperand result = va_arg(args, pOperand);
        pOperand op1 = va_arg(args, pOperand);
        pOperand op2 = va_arg(args, pOperand);
        code = newInterCode(kind, result, op1, op2);
        break;
    }
    case IR_IF_GOTO: {
        pOperand x = va_arg(args, pOperand);
        pOperand relop = va_arg(args, pOperand);
        pOperand y = va_arg(args, pOperand);
        pOperand z = va_arg(args, pOperand);
        code = newInterCode(kind, x, relop, y, z);
        break;
    }
    case IR_DEC: {
        pOperand op = va_arg(args, pOperand);
        int size = va_arg(args, int);
        code = newInterCode(kind, op, size);
        break;
    }
    }
    va_end(args);

    if (code) {
        pInterCodes node = newInterCodes(code);
        addInterCodes(interCodeList, node);
    }
}

void optimizeIR(pInterCodeList list) {
    (void)list;
    // IR optimization disabled: keeping code simple and safe
    // Future optimization opportunities:
    // 1. Remove dead code after unconditional jumps
    // 2. Merge consecutive labels
    // 3. Remove unreachable labels
    // These require careful implementation to avoid breaking program correctness
}


