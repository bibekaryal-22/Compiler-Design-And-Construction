%{
#include <stdio.h>
#include <stdlib.h>
int yylex(); 
void yyerror(const char *s);
%}
%token NUM ID NL
%left '+' '-'
%left '*' '/'
%%
input : E NL { printf("Valid expression\n"); exit(0); } ;
E : E '+' E | E '-' E | E '*' E | E '/' E
  | '(' E ')' | NUM | ID ;
%%
void yyerror(const char *s){ printf("Invalid expression\n"); exit(1); }
int main()
{
   printf("Enter expression: "); 
   yyparse(); 
   return 0; 
  }
