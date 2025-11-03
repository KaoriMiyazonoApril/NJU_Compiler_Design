// 词法分析需要给语法分析提供一个个的有值的语法单元,详见实现指导pdf
// 记得写一个makefile 看看能不能自动化测试
// 几个test样例我已经贴上去了,但是可能行号上有些出入,测试的时候注意

#include "lab1/Node/Node.h" //这里面包含了一些标准头文件,include上总没错
#include "syntax.tab.h"
#include"semantic.h"
extern Node *root;
extern void yyrestart(FILE *input_file);
extern int lab1_sign;

int main(int argc, char **argv){
    if (argc <= 1) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f){
        perror(argv[1]);
        return 1;
    }

    yyrestart(f);
    yyparse();

    if (lab1_sign) {
        // printTree(root, 0);
        traverseProgram(root);
    }
        
    freeTree(root);
    return 0;
}
