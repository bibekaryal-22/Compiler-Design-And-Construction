%{
#include <stdio.h>

int yylex(void);
int yyerror(const char *s);
%}

%token NUMBER

%%

E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | NUMBER
  ;

%%

int main()
{
    printf("Enter an arithmetic expression: ");

    if (yyparse() == 0)
        printf("Valid expression\n");

    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid expression\n");
    return 0;
}