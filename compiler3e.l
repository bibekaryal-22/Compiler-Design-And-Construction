%option noyywrap

%{
#include <stdio.h>
%}

%%

[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} {
    printf("Valid email\n");
}

.+ {
    printf("Invalid email\n");
}

%%

int main()
{
    printf("Enter email: ");
    yylex();
    return 0;
}