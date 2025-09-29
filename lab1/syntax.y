//author:dcy
//flex 需要传过来node* 内容的子节点
%{
    #include "Node/Node.h"
    #include "lex.yy.c"
    #include "syntax.tab.h"
    extern Node* root;
    extern int yylineno,lab1_sign;
    void yyerror(const char *msg);
%}

%union {
    Node* node;
    //如果以后还需要别的类型，也可以加在这里
}
//底层定义和接收这些节点的类型
%token INT FLOAT ID SEMI COMMA ASSIGNOP RELOP
%token PLUS MINUS STAR DIV AND OR DOT NOT
%token LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE TYPE

%type<node> INT FLOAT ID SEMI COMMA ASSIGNOP RELOP
%type<node> PLUS MINUS STAR DIV AND OR DOT NOT
%type<node> LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE TYPE

//高层定义,希望没少
%type<node> Program ExtDefList ExtDef ExtDecList Specifier FunDec VarDec ParamDec
%type<node> StructSpecifier OptTag DefList Tag VarList
%type<node> CompSt StmtList Exp Stmt Def DecList Dec Args

//优先级
%right ASSIGNOP
%left OR
%left AND
%nonassoc RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left DOT
%left LB RB
%left LP RP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%
Program : ExtDefList {
    $$ = newNodeN("Program","", $1 ? $1->lineNo : @$.first_line, 1, $1);
    root = $$;
};

ExtDefList : ExtDef ExtDefList {
    $$ = newNodeN("ExtDefList","", $1->lineNo, 2, $1, $2);
}
| /*Empty*/ { $$ = NULL; };

ExtDef : Specifier ExtDecList SEMI {
    $$ = newNodeN("ExtDef","", $1->lineNo, 3, $1, $2, $3);
}
| Specifier SEMI {
    $$ = newNodeN("ExtDef","", $1->lineNo, 2, $1, $2);
}
| Specifier FunDec CompSt {
    $$ = newNodeN("ExtDef","", $1->lineNo, 3, $1, $2, $3);
};

ExtDecList : VarDec {
    $$ = newNodeN("ExtDecList","", $1->lineNo, 1, $1);
}
| VarDec COMMA ExtDecList {
    $$ = newNodeN("ExtDecList","", $1->lineNo, 3, $1, $2, $3);
};

Specifier : TYPE {
    $$ = newNodeN("Specifier","", $1->lineNo, 1, $1);
}
| StructSpecifier {
    $$ = newNodeN("Specifier","", $1->lineNo, 1, $1);
};

StructSpecifier : STRUCT OptTag LC DefList RC {
    $$ = newNodeN("StructSpecifier","", $1->lineNo, 5, $1, $2, $3, $4, $5);
}
| STRUCT Tag {
    $$ = newNodeN("StructSpecifier","", $1->lineNo, 2, $1, $2);
};

OptTag : ID {
    $$ = newNodeN("OptTag","", $1->lineNo, 1, $1);
}
| /*Empty*/ { $$ = NULL; };

Tag : ID {
    $$ = newNodeN("Tag","", $1->lineNo, 1, $1);
};

VarDec : ID {
    $$ = newNodeN("VarDec","", $1->lineNo, 1, $1);
}
| VarDec LB INT RB {
    $$ = newNodeN("VarDec","", $1->lineNo, 4, $1, $2, $3, $4);
};

FunDec : ID LP VarList RP {
    $$ = newNodeN("FunDec","", $1->lineNo, 4, $1, $2, $3, $4);
}
| ID LP RP {
    $$ = newNodeN("FunDec","", $1->lineNo, 3, $1, $2, $3);
};

VarList : ParamDec COMMA VarList {
    $$ = newNodeN("VarList","", $1->lineNo, 3, $1, $2, $3);
}
| ParamDec {
    $$ = newNodeN("VarList","", $1->lineNo, 1, $1);
};

ParamDec : Specifier VarDec {
    $$ = newNodeN("ParamDec","", $1->lineNo, 2, $1, $2);
};

CompSt : LC DefList StmtList RC {
    $$ = newNodeN("CompSt","", $1->lineNo, 4, $1, $2, $3, $4);
}
|error RC{yyerrok;};

StmtList : Stmt StmtList {
    $$ = newNodeN("StmtList","", $1->lineNo, 2, $1, $2);
}
| /*Empty*/ { $$ = NULL; };

Stmt : Exp SEMI {
    $$ = newNodeN("Stmt","", $1->lineNo, 2, $1, $2);
}
| CompSt {
    $$ = newNodeN("Stmt","", $1->lineNo, 1, $1);
}
| RETURN Exp SEMI {
    $$ = newNodeN("Stmt","", $1->lineNo, 3, $1, $2, $3);
}
| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
    $$ = newNodeN("Stmt","", $1->lineNo, 5, $1, $2, $3, $4, $5);
}
| IF LP Exp RP Stmt ELSE Stmt {
    $$ = newNodeN("Stmt","", $1->lineNo, 7, $1, $2, $3, $4, $5, $6, $7);
}
| WHILE LP Exp RP Stmt {
    $$ = newNodeN("Stmt","", $1->lineNo, 5, $1, $2, $3, $4, $5);
}
|error SEMI {yyerrok;}
;

DefList : Def DefList {
    $$ = newNodeN("DefList","", $1->lineNo, 2, $1, $2);
}
| /*Empty*/ { $$ = NULL; };

Def : Specifier DecList SEMI {
    $$ = newNodeN("Def","", $1->lineNo, 3, $1, $2, $3);
};

DecList : Dec {
    $$ = newNodeN("DecList","", $1->lineNo, 1, $1);
}
| Dec COMMA DecList {
    $$ = newNodeN("DecList","", $1->lineNo, 3, $1, $2, $3);
};

Dec : VarDec {
    $$ = newNodeN("Dec","", $1->lineNo, 1, $1);
}
| VarDec ASSIGNOP Exp {
    $$ = newNodeN("Dec","", $1->lineNo, 3, $1, $2, $3);
};

Exp : Exp ASSIGNOP Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp AND Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp OR Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp RELOP Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp PLUS Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp MINUS Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp STAR Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp DIV Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| LP Exp RP {
    $$ = newNodeN("Exp","", $2->lineNo, 3, $1, $2, $3);
}
| MINUS Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 2, $1, $2);
}
| NOT Exp {
    $$ = newNodeN("Exp","", $1->lineNo, 2, $1, $2);
}
| ID LP Args RP {
    $$ = newNodeN("Exp","", $1->lineNo, 4, $1, $2, $3, $4);
}
| ID LP RP {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| Exp LB Exp RB {
    $$ = newNodeN("Exp","", $1->lineNo, 4, $1, $2, $3, $4);
}
| Exp DOT ID {
    $$ = newNodeN("Exp","", $1->lineNo, 3, $1, $2, $3);
}
| ID {
    $$ = newNodeN("Exp","", $1->lineNo, 1, $1);
}
| INT {
    $$ = newNodeN("Exp","", $1->lineNo, 1, $1);
}
| FLOAT {
    $$ = newNodeN("Exp","", $1->lineNo, 1, $1);
}
|error RP{yyerrok;};

Args : Exp COMMA Args {
    $$ = newNodeN("Args","", $1->lineNo, 3, $1, $2, $3);
}
| Exp {
    $$ = newNodeN("Args","", $1->lineNo, 1, $1);
};
%%


void yyerror(const char *msg) {
    lab1_sign=0;
    fprintf(stderr, "Error type B at Line %d: %s\n", yylineno, msg);
}