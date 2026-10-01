%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
%}


%%
-[0-9]+ {printf("Negative Number\n");}
0       {printf("ZERO....\n");}
[0-9]+  {printf("Positive Number\n");}
%%


int main()
{   
printf("Enter a number");
yylex();
return 0;
}
