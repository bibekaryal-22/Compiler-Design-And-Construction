%{
#include <stdio.h>

int yylex(void);
int yyerror(const char *s);
%}

%token A B

%%

S : A S B
  | A B
  ;

%%

int main()
{
    printf("Enter a string: ");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid string\n");
    return 0;
}