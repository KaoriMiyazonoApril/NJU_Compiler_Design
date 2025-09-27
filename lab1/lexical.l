/* lexical.l - Flex 词法分析器 */


%{
#include "Node/Node.h"
#include "syntax.tab.h"

extern int yylineno;
extern char* yytext;
%}



DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
INT_CONST   {DIGIT}+
FLOAT_CONST {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?

%%

"int"               { yylval.node = newNodeN("TYPE", "int", yylineno, 0); return TYPE; }
"float"             { yylval.node = newNodeN("TYPE", "float", yylineno, 0); return TYPE; }
"struct"            { yylval.node = newNodeN("STRUCT", "", yylineno, 0); return STRUCT; }
"return"            { yylval.node = newNodeN("RETURN", "", yylineno, 0); return RETURN; }
"if"                { yylval.node = newNodeN("IF", "", yylineno, 0); return IF; }
"else"              { yylval.node = newNodeN("ELSE", "", yylineno, 0); return ELSE; }
"while"             { yylval.node = newNodeN("WHILE", "", yylineno, 0); return WHILE; }



{INT_CONST}         { yylval.node = newNodeN("INT", yytext, yylineno, 0); return INT; }
{FLOAT_CONST}       { yylval.node = newNodeN("FLOAT", yytext, yylineno, 0); return FLOAT; }

{ID}                { yylval.node = newNodeN("ID", yytext, yylineno, 0); return ID; }


"=="    { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }
"!="    { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }
">="    { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }
"<="    { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }
">"     { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }
"<"     { yylval.node = newNodeN("RELOP", "", yylineno, 0); return RELOP; }

"="                 { yylval.node = newNodeN("ASSIGNOP", "", yylineno, 0); return ASSIGNOP; }
"+"                 { yylval.node = newNodeN("PLUS", "", yylineno, 0); return PLUS; }
"-"                 { yylval.node = newNodeN("MINUS", "", yylineno, 0); return MINUS; }
"*"                 { yylval.node = newNodeN("STAR", "", yylineno, 0); return STAR; }
"/"                 { yylval.node = newNodeN("DIV", "", yylineno, 0); return DIV; }

"&&"                { yylval.node = newNodeN("AND", "", yylineno, 0); return AND; }
"||"                { yylval.node = newNodeN("OR", "", yylineno, 0); return OR; }
"!"                 { yylval.node = newNodeN("NOT", "", yylineno, 0); return NOT; }
"."                 { yylval.node = newNodeN("DOT", "", yylineno, 0); return DOT; }

";"                 { yylval.node = newNodeN("SEMI", "", yylineno, 0); return SEMI; }
","                 { yylval.node = newNodeN("COMMA", "", yylineno, 0); return COMMA; }

"("                 { yylval.node = newNodeN("LP", "", yylineno, 0); return LP; }
")"                 { yylval.node = newNodeN("RP", "", yylineno, 0); return RP; }
"["                 { yylval.node = newNodeN("LB", "", yylineno, 0); return LB; }
"]"                 { yylval.node = newNodeN("RB", "", yylineno, 0); return RB; }
"{"                 { yylval.node = newNodeN("LC", "", yylineno, 0); return LC; }
"}"                 { yylval.node = newNodeN("RC", "", yylineno, 0); return RC; }


"//".*              { /* 忽略单行注释 */ }


"/*"([^*]|\*+[^*/])*\*+"/"   { /* 忽略多行注释 */ }

[ \t\r]+            { /* 忽略空格 */ }

.                   { fprintf(stderr, "Error type A at Line %d: Illegal character '%s'\n", yylineno, yytext); }
\n                  {yylineno++;}

%%

int yywrap(void) {
    return 1;
}
