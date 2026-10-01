%{
#include <stdio.h>

int yylex(void);
int yyerror(const char *s);
%}

%token LETTER DIGIT

%%

S : LETTER R
  ;

R : LETTER R
  | DIGIT R
  |
  ;

%%

int main()
{
    printf("Enter a variable: ");

    if (yyparse() == 0)
        printf("Valid variable\n");

    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid variable\n");
    return 0;
}