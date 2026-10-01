%option noyywrap

%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+    {
              yylval.value = atoi(yytext);
              return NUMBER;
          }

[ \t]     ;

\n        { return 0; }

[()+*/-]  { return yytext[0]; }

.         { return yytext[0]; }

%%