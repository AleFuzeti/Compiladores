%{
#include <stdio.h>
#include <string.h>
#include "lista.h"

// Var Bison 
extern int yylex();
void yyerror(char *s);
extern char* yytext;
extern int yychar;

int graphName;
Node* adj  = NULL;
Node* list = NULL;
Node* stack = NULL;
int degree = 0;
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
%token COLON

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
    : IDENTIFIER INTEGER COLON { graphName = $2; }
    | IDENTIFIER EQUAL INTEGER { k = $3; }
    | INTEGER ARROW Num {
        list = insertNode(list, adj, $1);
        adj = NULL;
        degree = 0;
        }
    ;

Num
    : INTEGER {
        adj = insertAdj(adj, $1, -1);
        degree++;
    }
    | Num INTEGER  {
        adj = insertAdj(adj, $2,-1);
        degree++;
    }

%%

void yyerror(char *s) {
    printf("SYNTAX ERROR: [%s]\n", yytext);
}
 
int main(int argc, char *argv[]){
    int result = 1;

    while (result != END_OF_FILE){    
        result = yyparse();
    }

    int vetSpill[k];
    for (int i = 0; i < k; i++){
        vetSpill[i] = 0;
    }

    printf("Graph %d -> Physical Registers: %d\n", graphName, k);
    printf("----------------------------------------\n");
    
    for (int i = k; i>=2; i--){
        printf("----------------------------------------\n");
        printf("K = %d\n\n", i);
        
        stack = montaPilha(stack, list, i);
        list = normalizeList(list);
        colorGraph(stack, i);

        freeStack(stack);
        stack = NULL;
        vetSpill[i] = spill;
        spill = 0;
    }

    printf("----------------------------------------\n");
    printf("----------------------------------------\n");

    for (int i = k; i>=2; i--){
        if (vetSpill[i] == 0){
            printf("Graph %d -> K =", graphName);
            printf("%*d: ", countDigits(k) + 1, i);
            printf("Successful Allocation");
        } else{
            printf("Graph %d -> K =", graphName);
            printf("%*d: ", countDigits(k) + 1, i);
            printf("SPILL");
        }
        if (i !=2 )
        printf("\n");
    }

    freeList(list);
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