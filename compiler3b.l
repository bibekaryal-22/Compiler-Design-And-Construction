%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%%

[0-9]+      {
                int num = atoi(yytext);
                if (num % 2 == 0)
                    printf("%d is Even\n", num);
                else
                    printf("%d is Odd\n", num);
            }

%%

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}