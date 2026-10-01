%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%%

[0-9]+      {
                int num = atoi(yytext);
                if (num % 2 == 0)
                    printf("%d is a digit\n", num);
            }
.*  {
    printf("Not a digit");
}
%%

int main() {
    printf("Enter anything: ");
    yylex();
    return 0;
}