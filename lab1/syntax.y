//author:dcy
//flex 需要传过来node* 内容的子节点
%{
    #include "Node/Node.h"
    #include "lex.yy.c"
    #include "syntax.tab.h"
    extern Node* root;
    extern int yylineno;
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
Program : ExtDefList {$$=newNodeN("Program","",@$.first_line,1,$1);root=$$;};

ExtDefList : ExtDef ExtDefList {$$=newNodeN("ExtDefList","",@$.first_line,2,$1,$2);}
| /*Empty*/{$$=NULL;};

ExtDef : Specifier ExtDecList SEMI{$$=newNodeN("ExtDef","",@$.first_line,3,$1,$2,$3);}
| Specifier SEMI {$$=newNodeN("ExtDef","",@$.first_line,2,$1,$2);}
| Specifier FunDec CompSt{$$=newNodeN("ExtDef","",@$.first_line,3,$1,$2,$3);};

ExtDecList : VarDec{$$=newNodeN("ExtDecList","",@$.first_line,1,$1);}
| VarDec COMMA ExtDecList{$$=newNodeN("ExtDecList","",@$.first_line,3,$1,$2,$3);};

Specifier : TYPE{$$=newNodeN("Specifier","",@$.first_line,1,$1);}
| StructSpecifier{$$=newNodeN("Specifier","",@$.first_line,1,$1);};

StructSpecifier : STRUCT OptTag LC DefList RC{$$=newNodeN("StructSpecifier","",@$.first_line,5,$1,$2,$3,$4,$5);}
| STRUCT Tag{$$=newNodeN("StructSpecifier","",@$.first_line,2,$1,$2);};

OptTag : ID{$$=newNodeN("OptTag","",@$.first_line,1,$1);}
| /*Empty*/{$$=NULL;};

Tag : ID{$$=newNodeN("Tag","",@$.first_line,1,$1);};

VarDec : ID{$$=newNodeN("VarDec","",@$.first_line,1,$1);}
| VarDec LB INT RB{$$=newNodeN("VarDec","",@$.first_line,4,$1,$2,$3,$4);};

FunDec : ID LP VarList RP{$$=newNodeN("FunDec","",@$.first_line,4,$1,$2,$3,$4);}
| ID LP RP{$$=newNodeN("FunDec","",@$.first_line,3,$1,$2,$3);};

VarList : ParamDec COMMA VarList{$$=newNodeN("VarList","",@$.first_line,3,$1,$2,$3);}
| ParamDec{$$=newNodeN("VarList","",@$.first_line,1,$1);};

ParamDec : Specifier VarDec{$$=newNodeN("ParamDec","",@$.first_line,2,$1,$2);};

CompSt : LC DefList StmtList RC{$$=newNodeN("CompSt","",@$.first_line,4,$1,$2,$3,$4);};

StmtList : Stmt StmtList{$$=newNodeN("StmtList","",@$.first_line,2,$1,$2);}
| /*Empty*/{$$=NULL;};

Stmt : Exp SEMI{$$=newNodeN("Stmt","",@$.first_line,2,$1,$2);}
| CompSt{$$=newNodeN("Stmt","",@$.first_line,1,$1);}
| RETURN Exp SEMI{$$=newNodeN("Stmt","",@$.first_line,3,$1,$2,$3);}
| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE{$$=newNodeN("Stmt","",@$.first_line,5,$1,$2,$3,$4,$5);}
| IF LP Exp RP Stmt ELSE Stmt{$$=newNodeN("Stmt","",@$.first_line,7,$1,$2,$3,$4,$5,$6,$7);}
| WHILE LP Exp RP Stmt{$$=newNodeN("Stmt","",@$.first_line,5,$1,$2,$3,$4,$5);};

DefList : Def DefList{$$=newNodeN("DefList","",@$.first_line,2,$1,$2);}
| /*Empty*/{$$=NULL;};

Def : Specifier DecList SEMI{$$=newNodeN("Def","",@$.first_line,3,$1,$2,$3);};

DecList : Dec{$$=newNodeN("DecList","",@$.first_line,1,$1);}
| Dec COMMA DecList{$$=newNodeN("DecList","",@$.first_line,3,$1,$2,$3);};

Dec : VarDec{$$=newNodeN("Dec","",@$.first_line,1,$1);}
| VarDec ASSIGNOP Exp{$$=newNodeN("Dec","",@$.first_line,3,$1,$2,$3);};

Exp : Exp ASSIGNOP Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp AND Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp OR Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp RELOP Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp PLUS Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp MINUS Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp STAR Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp DIV Exp{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| LP Exp RP{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| MINUS Exp{$$=newNodeN("Exp","",@$.first_line,2,$1,$2);}
| NOT Exp{$$=newNodeN("Exp","",@$.first_line,2,$1,$2);}
| ID LP Args RP{$$=newNodeN("Exp","",@$.first_line,4,$1,$2,$3,$4);}
| ID LP RP{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| Exp LB Exp RB{$$=newNodeN("Exp","",@$.first_line,4,$1,$2,$3,$4);}
| Exp DOT ID{$$=newNodeN("Exp","",@$.first_line,3,$1,$2,$3);}
| ID{$$=newNodeN("Exp","",@$.first_line,1,$1);}
| INT{$$=newNodeN("Exp","",@$.first_line,1,$1);}
| FLOAT{$$=newNodeN("Exp","",@$.first_line,1,$1);};

Args : Exp COMMA Args{$$=newNodeN("Args","",@$.first_line,3,$1,$2,$3);}
| Exp{$$=newNodeN("Args","",@$.first_line,1,$1);};

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error type B at Line  %d: %s\n", yylineno, msg);
}