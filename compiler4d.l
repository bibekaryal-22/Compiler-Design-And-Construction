%option noyywrap

%{
#include <stdio.h>
%}

%%

[0-9]+([+\-*/][0-9]+)+ {
    printf("Valid arithmetic expression\n");
}

[0-9]+ {
    printf("Valid number\n");
}

[ \t\n]+ {
    /* Ignore whitespace */
}

.* {
    printf("Invalid arithmetic expression\n");
}

%%

int main()
{
    printf("Enter an arithmetic expression: ");
    yylex();
    return 0;
}