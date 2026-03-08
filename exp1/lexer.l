%{
#include <stdio.h>
%}

%%

int|float|if|else|return     { printf("<KEYWORD, %s>\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*       { printf("<IDENTIFIER, %s>\n", yytext); }
[0-9]+                       { printf("<NUMBER, %s>\n", yytext); }
"="                          { printf("<ASSIGN_OP, %s>\n", yytext); }
"+"|"-"|"*"|"/"              { printf("<ARITH_OP, %s>\n", yytext); }
">="|"<="|"=="|">"|"<"       { printf("<REL_OP, %s>\n", yytext); }
";"                          { printf("<SEMICOLON>\n"); }
"("                          { printf("<LPAREN>\n"); }
")"                          { printf("<RPAREN>\n"); }
[ \t\n]+                     ;   
.                            { printf("<INVALID, %s>\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    freopen("lex_output.txt", "w", stdout);  // Save output to file
    printf("Lexical Analysis Output\n\n");
    yylex();
    return 0;
}