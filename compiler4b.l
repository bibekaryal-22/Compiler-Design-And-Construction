%option noyywrap

%{
#include <stdio.h>
%}

%%

"++"|"--"|"=="|"!="|"<="|">="|"&&"|"||" {
    printf("Valid operator: %s\n", yytext);
}

"+"|"-"|"*"|"/"|"%"|"="|"<"|">" {
    printf("Valid operator: %s\n", yytext);
}

[ \t\n]+ {
    /* Ignore whitespace */
}

. {
    printf("Invalid operator: %s\n", yytext);
}

%%

int main()
{
    printf("Enter operators:\n");
    yylex();
    return 0;
}