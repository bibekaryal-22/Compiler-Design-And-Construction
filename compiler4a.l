%option noyywrap

%{
#include <stdio.h>
%}

%%

"int"|"float"|"char"|"double"|"if"|"else"|"for"|"while"|"return" {
    printf("Keyword: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier: %s\n", yytext);
}

[0-9]+ {
    printf("Number: %s\n", yytext);
}

[ \t\n]+ {
    /* Ignore whitespace */
}

. {
    printf("Invalid: %s\n", yytext);
}

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}