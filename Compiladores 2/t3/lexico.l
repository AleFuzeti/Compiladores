%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sintatico.tab.h"

%}

%%
      
"="             { return EQUAL; }
"--> "          { return ARROW; }

[a-zA-Z][a-zA-Z0-9]* { char* aux = (char *) malloc(strlen(yytext) + 1);
                                        if (aux != NULL) strcpy(aux, yytext);
                                        yylval.strval = aux;
                                        return IDENTIFIER; }
[0-9][0-9]*          { yylval.intval = atoi(yytext); return INTEGER; }
[ \r\t\f]                  { }
\n                  { return NEW_LINE;}
<<EOF>>          { return END_OF_FILE;}

. { printf("Invalid Symbol: %s\n", yytext); return ERROR; }

%%