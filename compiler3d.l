%option noyywrap

%{
#include <stdio.h>
%}

%%

(98|97)[0-9]{8}      { printf("Valid mobile number\n"); }
[0-9]+               { printf("Invalid mobile number\n"); }
.                    { printf("Invalid mobile number\n"); }

%%

int main()
{
    printf("Enter mobile number: ");
    yylex();
    return 0;
}