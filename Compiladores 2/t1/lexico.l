%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "sintatico.tab.h"
char* buffer;

%}

%%
      
"about"         { return ABOUT; }
"abs"           { return ABS; }
"axis"          { return AXIS; }
"connect_dots"  { return CONNECT_DOTS; }
"cos"           { return COS; }
"determinant"   { return DETERMINANT; }
[eE]            { return E; }
"erase"         { return ERASE; }
"float"         { return FLOAT; }
"h_view"        { return H_VIEW; }
"integral_steps" { return INTEGRAL_STEPS; }
"integrate"     { return INTEGRATE; }
"linear_system" { return LINEAR_SYSTEM; }
"matrix"        { buffer = yytext;
                        return MATRIX; }
"off"           { return OFF; }
"on"            { return ON; }
[pP][iI]        { return PI; }
"plot"          { return PLOT; }
"precision"     { return PRECISION; }
"quit"          { return QUIT; }
"reset"         { return RESET; }
"rpn"           { return RPN; }
"sen"           { return SEN; }
"set"           { return SET; }
"settings"      { return SETTINGS; }
"show"          { return SHOW; }
"solve"         { return SOLVE; }
"sum"           { return SUM; }
"symbols"       { return SYMBOLS; }
"tan"           { return TAN; }
"v_view"        { return V_VIEW; }
[xX]             { return X; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }
"^"             { return POWER; }
"%"             { return MOD; }
"("             { return OPEN_PAR; }
")"             { return CLOSE_PAR; }
":"             { return COLON; }
"="             { return EQUAL; }
":="            { return ASSIGN; }
"["             { return OPEN_BRA; }
"]"             { return CLOSE_BRA; }
";"             { return SEMICOLON; }
","             { return COMMA; }

[a-zA-Z][_a-zA-Z0-9]* { char* aux = (char *) malloc(strlen(yytext) + 1);
                                        if (aux != NULL) strcpy(aux, yytext);
                                        yylval.strval = aux;
                                        buffer = yytext;
                                        return IDENTIFIER; }
[0-9][0-9]*          { yylval.intval = atoi(yytext); return INTEGER; }
[0-9]+[.][0-9]+     { yylval.realval = atof(yytext); return REAL; }
" "                  { }
\n                  { return NEW_LINE;}
<<EOF>>          { return END_OF_FILE;}
. { printf("Invalid Symbol: %s\n", yytext); return ERROR; }

%%