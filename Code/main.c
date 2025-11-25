// 词法分析需要给语法分析提供一个个的有值的语法单元,详见实现指导pdf
// 记得写一个makefile 看看能不能自动化测试
// 几个test样例我已经贴上去了,但是可能行号上有些出入,测试的时候注意

#include <stdio.h>
#include <string.h>
#include "lab1/Node/Node.h" //这里面包含了一些标准头文件,include上总没错
#include "syntax.tab.h"
#include "semantic.h"
#include "lab3/IR.h"

extern Node *root;
extern void yyrestart(FILE *input_file);
extern int lab1_sign;
extern pInterCodeList interCodeList;

int main(int argc, char **argv) {
    if (argc <= 1)
        return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }

    yyrestart(f);
    yyparse();

    if (lab1_sign) {
        // printTree(root, 0);
        if (!semanticAnalysis(root)) {
            // Cannot translate, error message already printed
            freeTree(root);
            freeSemanticResource();
            if (interCodeList) {
                deleteInterCodeList(interCodeList);
            }
            return 0;
        }

        // 生成中间代码
        generateIRFromAST(root);

        // 如果提供了输出文件名，输出中间代码到文件
        if (argc > 2) {
            FILE *out = fopen(argv[2], "w");
            if (!out) {
                perror(argv[2]);
                freeTree(root);
                freeSemanticResource();
                if (interCodeList) {
                    deleteInterCodeList(interCodeList);
                }
                return 1;
            }
            printInterCode(out, interCodeList);
            fclose(out);
        }
    }

    freeTree(root);
    freeSemanticResource();
    if (interCodeList) {
        deleteInterCodeList(interCodeList);
    }
    return 0;
}
