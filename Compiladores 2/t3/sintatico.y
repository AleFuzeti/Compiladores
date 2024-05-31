%{
#include <stdio.h>
#include <string.h>
#include "lista.h"

// Var Bison 
extern int yylex();
void yyerror(char *s);
extern char* yytext;
extern int yychar;

Node* head  = NULL;
int k = 0;
int spill = 0;

%}
%union{
    int intval;
    char *strval;
}

%token <strval> IDENTIFIER
%token <intval> INTEGER

%token EQUAL
%token ARROW
%token ERROR

%token NEW_LINE
%token END_OF_FILE

%start Programa

%%

Programa
    : Comandos { return 1; }
    | ERROR { return 0; }
    | END_OF_FILE { return END_OF_FILE;}
    ;

Comandos
    : Funcoes { return 1; }
    | Funcoes NEW_LINE { return 1; }
    ;

Funcoes
    : IDENTIFIER EQUAL INTEGER { 
        k = $3;
        }
    | IDENTIFIER ARROW INTEGER INTEGER { 
        char* name = $1;
        int init = $3;
        int end = $4;
        insertNode(&head, name, init, end);
        }
    ;

%%


void yyerror(char *s) {
    printf("SYNTAX ERROR: [%s]\n", yytext);
}
 
int main(int argc, char *argv[]){
    int result = 1;

    while (result != END_OF_FILE){    
        result = yyparse();
    }
    char* regis[k];
    int vetSpill[k];

    for (int i = k; i >= 2; i--){
        vetSpill[i] = 0;
        regis[i] = "0";

        printf("K = %d\n\n", i);

        AllocRegis(i, head, regis);
        
        vetSpill[i] = spill;
        spill = 0;

        printf("----------------------------------------\n");
    }
    printf("----------------------------------------\n");
    
    for (int i = k; i>=2; i--){
        if (vetSpill[i] == 0){
            printf("K =");
            printf("%*d: ", countDigits(k) + 1, i);
            printf("Successful Allocation");
        } else{
            printf("K =");
            printf("%*d: ", countDigits(k) + 1, i);
            printf("SPILL on interation(s): %s", regis[i]);
        }
        if (i !=2 )
        printf("\n");
    }

    freeList(head);
    yylex_destroy();
    return 0; 
}

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}