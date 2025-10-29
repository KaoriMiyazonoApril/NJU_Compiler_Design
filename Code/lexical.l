/* lexical.l - Flex 词法分析器 */


%{
#include "Node/Node.h"
#include "syntax.tab.h"

extern int yylineno,lab1_sign,last_error_line;
extern char* yytext;
%}



DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
DEC         0|[1-9]{DIGIT}*
OCT         0[0-7]+
HEX         (0x|0X)[0-9a-fA-F]+
FLOAT       {DIGIT}+\.{DIGIT}+
ERROR_FLOAT (({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)[eE][+-]?{DIGIT}+)
%%

"int"               { yylval.node = newNodeN("TYPE", "int", yylineno, 0); return TYPE; }
"float"             { yylval.node = newNodeN("TYPE", "float", yylineno, 0); return TYPE; }
"struct"            { yylval.node = newNodeN("STRUCT", "", yylineno, 0); return STRUCT; }
"return"            { yylval.node = newNodeN("RETURN", "", yylineno, 0); return RETURN; }
"if"                { yylval.node = newNodeN("IF", "", yylineno, 0); return IF; }
"else"              { yylval.node = newNodeN("ELSE", "", yylineno, 0); return ELSE; }
"while"             { yylval.node = newNodeN("WHILE", "", yylineno, 0); return WHILE; }

{HEX}       { 	if (yylineno != last_error_line) {
                          last_error_line = yylineno;
                          lab1_sign = 0;
                          fprintf(stderr, "Error type A at Line %d: Illegal character '%s'\n", yylineno, yytext);
         	}
		yylval.node = newNodeN("INT", yytext, yylineno, 0); return INT; }
{OCT}       {   if (yylineno != last_error_line) {
                          last_error_line = yylineno;
                          lab1_sign = 0;
                          fprintf(stderr, "Error type A at Line %d: Illegal character '%s'\n", yylineno, yytext);
                }
		yylval.node = newNodeN("INT", yytext, yylineno, 0); return INT; }

{DEC}         { yylval.node = newNodeN("INT", yytext, yylineno, 0); return INT; }
{ERROR_FLOAT} {if (yylineno != last_error_line) {
                          last_error_line = yylineno;
                          lab1_sign = 0;
                          fprintf(stderr, "Error type A at Line %d: Illegal character '%s'\n", yylineno, yytext);
                }
                      double value = atof(yytext);
                      char decimal[64];
                      snprintf(decimal, sizeof(decimal), "%.6f", value);
                      yylval.node = newNodeN("FLOAT", decimal, yylineno, 0); 
                      //printf("Lexer: Found FLOAT '%s' at line %d\n", yytext, yylineno);
                      return FLOAT; 
              }
{FLOAT}       { 
                      double value = atof(yytext);
                      char decimal[64];
                      snprintf(decimal, sizeof(decimal), "%.6f", value);
                      yylval.node = newNodeN("FLOAT", decimal, yylineno, 0); 
                      //printf("Lexer: Found FLOAT '%s' at line %d\n", yytext, yylineno);
                      return FLOAT;  
                    }

{ID}                { yylval.node = newNodeN("ID", yytext, yylineno, 0); return ID; }

"//"        { int c;
    while ((c = input()) != '\n' && c != EOF) {
        // 消耗注释内容，直到换行
    }
    if (c == '\n') {
        yylineno++;  // 遇到换行符，增加行号
    } }
"/*"        { int a = input();
    int b = input();
    while (!(a == '*' && b == '/')) {
        if (a == '\n') {
            yylineno++;  // 遇到换行符，增加行号
        }
        a = b;
        b = input();
        if (b == EOF) {
            // 处理未闭合的注释错误
            break;
        }
    } }

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


 
[ \t\r]+            { /* 忽略空格 */ }

.                   {  if (yylineno != last_error_line) {
                          last_error_line = yylineno;
                          lab1_sign = 0;
                          fprintf(stderr, "Error type A at Line %d: Illegal character '%s'\n", yylineno, yytext);
                          }
                    }
\n                  {yylineno++;}

%%

int yywrap(void) {
    return 1;
}
