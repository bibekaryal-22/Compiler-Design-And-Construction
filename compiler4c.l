%option noyywrap

%{
#include <stdio.h>
%}

%%

[a-z]+ {
    printf("Small case letters\n");
}

[A-Z]+ {
    printf("Upper case letters\n");
}

[a-z]*[A-Z][a-zA-Z]*|[A-Z]*[a-z][a-zA-Z]* {
    printf("Mixed case letters\n");
}

[ \t\n]+ {
    /* Ignore whitespace */
}

. {
    printf("Invalid input\n");
}

%%

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}