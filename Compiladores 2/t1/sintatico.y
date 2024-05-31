%{
#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include "hash.h"
#include "ast.h"

// Var Bison 
extern int yylex();
void yyerror(char *s);
extern char* yytext;
extern int yychar;

extern char* buffer;

// Var globais para o plot
float h_view_lo = H_VIEW_LO_;
float h_view_hi = H_VIEW_HI_;
float v_view_lo = V_VIEW_LO_;
float v_view_hi = V_VIEW_HI_;
int float_precision = FLOAT_PRECISION;
int   integral_steps = INTEGRAL_STEPS__;
int   draw_axis = DRAW_AXIS; 
int   erase_plot = ERASE_PLOT;
int   connect_dots = CONNECT_DOTS_;
char plot[HEIGHT][WIDTH];

// Var globais para a hash table
hash_table* ht;

// Var globais para a estrutura da arvore
TreeNode * AST = NULL;
TreeNode * Expre = NULL;
float x_expr = 0.0;

// Var globais para erro
int tem_x = 0;
int var_n_found = 0;
int op_error = 0;

// Var globais para a matriz
matrix* Mat;
int matrix_value = 0;

%}
%union{
    int intval;
    float realval;
    char *strval;
    TreeNode *ast;
}

%token <strval> IDENTIFIER
%token <intval> INTEGER
%token <realval> REAL

%type <intval> Signal
%type <ast> Num
%type <ast> Expressao
%type <ast> Termo
%type <ast> Fator
%type <ast> Pow
%type <ast> Funcao
%type <ast> Cons

%token ABOUT
%token ABS
%token AXIS
%token CONNECT_DOTS
%token COS
%token DETERMINANT
%token E
%token ERASE
%token FLOAT
%token H_VIEW
%token INTEGRAL_STEPS
%token INTEGRATE
%token LINEAR_SYSTEM
%token MATRIX
%token OFF
%token ON
%token PI
%token PLOT
%token PRECISION
%token QUIT
%token RESET
%token RPN
%token SEN
%token SET
%token SETTINGS
%token SHOW
%token SOLVE
%token SUM
%token SYMBOLS
%token TAN
%token V_VIEW
%token X

%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token POWER
%token MOD
%token OPEN_PAR
%token CLOSE_PAR
%token COLON
%token EQUAL
%token ASSIGN
%token OPEN_BRA
%token CLOSE_BRA
%token SEMICOLON
%token COMMA
%token ERROR

%token NEW_LINE
%token EXIT
%token END_OF_FILE

%start Programa

%%

Programa
    : Sentenca NEW_LINE { return 0; }
    | QUIT NEW_LINE { return QUIT_; }
    | NEW_LINE { return 0; }
    | Expressao {
        AST = $1;
        if (AST != NULL) {
            Eval_Ast(AST); // verifica erros
            if (!var_n_found && !op_error){
                Eval_Ast(AST); // arruma o negativo dos nós
                if (!tem_x) {
                    TreeNode* Aux = NULL;
                    Aux = Eval_Ast(AST);
                    if (Aux->type == 'f') {
                        print_formated_number(Aux->value, 1);
                        printf("\n");
                    } else {
                        matrix_print(Aux->m);
                    }
                } else {
                    printf("\nThe x variable cannot be present on expressions.\n\n");
                    tem_x = 0;
                }
            } else { // reseta os erros
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        }
        return 0;
    }
    | ERROR { return 0; }
    ;

Sentenca
    : Settings { }
    | Set { }
    | Plot { }
    | Rpn { }
    | Integrate { }
    | Sum { }
    | Matrix { }
    | Solve { }
    | About { }
    | Atribuicao { }
    | IDENTIFIER SEMICOLON {
        float num = hash_table_search(ht, $1); 
        if (num == NOT_FIND) {
            printf("Undefined symbol\n", $1);
        }
        else {
            if (get_type(ht, $1) == 'f'){
                printf("\n%s = ", $1);
                print_formated_number(num, 0);
                printf("\n\n");
            } else {
                get_print_matrix(ht, $1);
            }
        }
     }
    ;

Settings
    : SHOW SETTINGS SEMICOLON { ShowSettings(); }
    | RESET SETTINGS SEMICOLON { ResetSettings(); }
    | SHOW SYMBOLS SEMICOLON { hash_table_print(ht); }
    ;

Set
    : SET H_VIEW Num COLON Num SEMICOLON{ 
        float hlo = Get_Value($3); float hhi = Get_Value($5); 
        if (hhi < hlo) printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n"); 
        else { h_view_hi = hhi; h_view_lo = hlo; }
        initialize_plot(plot);}
    | SET V_VIEW Num COLON Num SEMICOLON{ 
        float vhi = Get_Value($5); float vlo = Get_Value($3);
        if (vhi < vlo) printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n"); 
        else { v_view_hi = vhi; v_view_lo = vlo; }
        initialize_plot(plot);}
    | SET AXIS ON SEMICOLON{ draw_axis = 1; }
    | SET AXIS OFF SEMICOLON{ draw_axis = 0; }
    | SET ERASE PLOT ON SEMICOLON{ erase_plot = 1; }
    | SET ERASE PLOT OFF SEMICOLON{ erase_plot = 0; }
    | SET INTEGRAL_STEPS Num SEMICOLON { 
        if ((int)Get_Value($3)<1) printf("\nERROR: integral_steps must be a positive non-zero integer\n\n"); 
        else integral_steps = (int)Get_Value($3); }
    | SET FLOAT PRECISION Num SEMICOLON { 
        int pre = (int)Get_Value($4);
        if(pre < 0 || pre > 8) printf("\nERROR: float precision must be from 0 to 8\n\n");
        else float_precision = pre; }
    ;

Plot
    : PLOT OPEN_PAR Expressao CLOSE_PAR SEMICOLON{
        AST = $3;
        if (AST != NULL) {
            printf("\n");
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                Set_Expre(AST);
                if (Expre->type = 'm'){
                    printf("\nERROR: The expression must be a function\n\n");
                    Set_Expre(NULL);
                    Delete_Tree(AST);
                } else plot_function(plot, Expre);
            }
            else {
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        }
        printf("\n");
        tem_x = 0;
    }
    | PLOT SEMICOLON{ 
        if(!Expre) printf("\n No Function defined!\n\n");
        else plot_function(plot, Expre);
    }
    ;

Rpn 
    : RPN OPEN_PAR Expressao CLOSE_PAR SEMICOLON { 
        AST = $3;
        if (AST != NULL) {
            printf("\nExpression in RPN format:\n\n");
            RPN_Walk(AST);
            printf("\n");
        } else printf("ast null\n");
        printf("\n");
        var_n_found = 0; 
        op_error = 0;
        tem_x = 0;
        Delete_Tree(AST);
    }
    ;

Integrate
    : INTEGRATE OPEN_PAR Num COLON Num COMMA Expressao CLOSE_PAR SEMICOLON { 
        if (Get_Value($3) > Get_Value($5)) printf("\nERROR: Lower limit must be smaller than upper limit\n\n");
        else {
            AST = $7;
            if (AST != NULL) {
            float inf = Get_Value($3);
            float sup = Get_Value($5);
            printf("\n");
            float result = integral_ast(AST, inf, sup, integral_steps);
            if (!var_n_found && !op_error){
                printf("%f\n", result);
            }
            else {
                var_n_found = 0; 
                op_error = 0;
            }
            Delete_Tree(AST);
            printf("\n");
            } else printf("ast null\n");
            tem_x = 0;
        }
    }
    ;

Sum 
    : SUM OPEN_PAR IDENTIFIER COMMA INTEGER COLON INTEGER COMMA Expressao CLOSE_PAR SEMICOLON{
        AST = $9;
        float sum = 0;
        float inf = (float)$5;
        float sup = (float)$7;
        var_n_found = 0;
        if (AST != NULL) {
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                float num = hash_table_search(ht, $3); 
                for (int i = inf; i <= sup; i++) {
                    if(var_n_found) break;
                    hash_table_insert(ht, $3, (float)i);
                    sum += Get_Value(Eval_Ast(AST));
                    hash_table_remove(ht, $3);
                }
                if(num != NOT_FIND) hash_table_insert(ht, $3, num);
                printf("\n%f\n\n", sum);
            }
            else {
                var_n_found = 0; 
                op_error = 0;
            }
            Delete_Tree(AST);
        } else printf("ast null\n");
    }
    ; 

Matrix 
    : MATRIX EQUAL OPEN_BRA OPEN_BRA Value CLOSE_BRA Dimensao CLOSE_BRA SEMICOLON{ 
        matrix_value   = 1;
        Mat = matrix_grammar(buffer, "matrix", ht);
    }
    | IDENTIFIER ASSIGN OPEN_BRA OPEN_BRA Value CLOSE_BRA Dimensao CLOSE_BRA SEMICOLON{
        matrix_grammar(buffer, $1, ht);
        get_print_matrix(ht, $1);
    }
    | SHOW MATRIX SEMICOLON{
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            matrix_print(Mat);
        }
    }
    ;

Dimensao
    :  COMMA OPEN_BRA Value CLOSE_BRA Dimensao { }
    | { }
    ;

Value   
    : Num { }
    | Num COMMA Value { }
    ;

Solve
    : SOLVE LINEAR_SYSTEM SEMICOLON { 
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            solve_linear_system(Mat);
        }
     }
    | SOLVE DETERMINANT SEMICOLON {  
        if (matrix_value == 0) {
            printf("\nNo Matrix defined!\n\n");
        } else {
            if (matrix_determinant(Mat) != NOT_FIND)
            printf("\n%f\n\n", matrix_determinant(Mat));
        }
     }
    ;

About
    : ABOUT SEMICOLON{ About(); }
    ;
   
Atribuicao
    : IDENTIFIER ASSIGN Expressao SEMICOLON { 
        AST = $3;
        if (AST != NULL) { 
            Eval_Ast(AST);
            if (!var_n_found && !op_error){
                if (!tem_x) {
                    TreeNode* Aux = NULL;
                    Aux = Eval_Ast(AST);
                    if (Aux->type == 'f') {
                        print_formated_number(Aux->value, 1);
                        printf("\n");
                        hash_table_insert(ht, $1, Aux->value);
                    } else {
                        matrix_print(Aux->m);
                        htable_insert_matrix(ht, $1, Aux->m);
                    } 
                } else {
                    printf("\nThe x variable cannot be present on expressions.\n\n");
                    tem_x = 0;
                }
            Delete_Tree(AST); 
            } else {
                var_n_found = 0; 
                op_error = 0;
                Delete_Tree(AST);
            }
        }
    }
    ;

Expressao
    : Termo { $$ = $1; }
    | Expressao PLUS Termo             { $$ = Create_Node(PLUS, $1, $3, 0); }
    | Expressao MINUS Termo         { $$ = Create_Node(MINUS, $1, $3, 0);}
    ;

Termo
    : Pow { $$ = $1; }
    | Termo TIMES Pow             { $$ = Create_Node(TIMES, $1, $3, 0); }
    | Termo DIVIDE Pow            { $$ = Create_Node(DIVIDE, $1, $3, 0); }
    ;

Pow
    : Fator { $$ = $1; }
    | Pow POWER Fator { $$ = Create_Node(POWER, $1, $3, 0);}
    ; 

Fator
    : Num { $$ = $1; }
    | Signal OPEN_PAR Expressao CLOSE_PAR { $$ = $3; Set_Sinal($$, $$->sinal *$1);}
    | Signal Funcao { $$ = $2; Set_Sinal($$, $$->sinal *$1); }
    | Cons { $$ = $1; }
    ;

Funcao
    : SEN OPEN_PAR Expressao CLOSE_PAR  { $$  = Create_Node(SEN, $3, NULL, 0); }
    | COS OPEN_PAR Expressao CLOSE_PAR  { $$  = Create_Node(COS, $3, NULL, 0); }
    | TAN OPEN_PAR Expressao CLOSE_PAR  { $$  = Create_Node(TAN, $3, NULL, 0); }
    | ABS OPEN_PAR Expressao CLOSE_PAR   { $$  = Create_Node(ABS, $3, NULL, 0); }
    ;

Num 
    : Signal INTEGER { $$ = Create_Node(INTEGER, NULL, NULL, (float)$2); Set_Sinal($$, $1); }
    | Signal REAL { $$ =  Create_Node(INTEGER, NULL, NULL, $2); Set_Sinal($$, $1); }
    ;

Signal
    : PLUS { $$ = 1; }
    | MINUS { $$ = -1; }
    | { $$ = 1; }
    ;

Cons
    : Signal PI { $$ = Create_Node(INTEGER, NULL, NULL, PI_); Set_Sinal($$, $1);}
    | Signal E { $$ = Create_Node(INTEGER, NULL, NULL, E_); Set_Sinal($$, $1);}
    | X { $$ = Create_Node(X, NULL, NULL, 0); tem_x = 1;}
    | PLUS X { $$ = Create_Node(X, NULL, NULL, 0); tem_x = 1;}
    | MINUS X { $$ = Create_Node(X, NULL, NULL, 0); tem_x = 1; Set_Sinal($$, -1);}
    | IDENTIFIER { 
        float num = hash_table_search(ht, $1); 
            if (num == NOT_FIND) {
                //printf("Undefined symbol [%s]\n", $1);
                var_n_found = 1;
                $$ = Create_Node(IDENTIFIER, NULL, NULL, 0);
            }
            else {
                $$ = Create_Node(IDENTIFIER, NULL, NULL, (float)num);
            }
                Set_Name($$,$1);
        }
    | PLUS IDENTIFIER { 
        float num = hash_table_search(ht, $2); 
            if (num == NOT_FIND) {
                //printf("Undefined symbol [%s]\n", $1);
                var_n_found = 1;
                $$ = Create_Node(IDENTIFIER, NULL, NULL, 0);
            }
            else {
                $$ = Create_Node(IDENTIFIER, NULL, NULL, (float)num);
            }
                Set_Name($$,$2);
        }
    | MINUS IDENTIFIER { 
        float num = hash_table_search(ht, $2); 
            if (num == NOT_FIND) {
                var_n_found = 1;
                $$ = Create_Node(IDENTIFIER, NULL, NULL, 0);
                Set_Sinal($$, -1);
            }
            else {
                $$ = Create_Node(IDENTIFIER, NULL, NULL, (float)num);
                Set_Sinal($$, -1);
            }
                Set_Name($$,$2);
        }
    ;

%%

void yyerror(char *s) {
    if( yychar == NEW_LINE) printf("\nSYNTAX ERROR: Incomplete Command\n\n");
    else printf("SYNTAX ERROR: [%s]\n", yytext);
}
 
int main(int argc, char *argv[]){
    int result = 1;
    
    // Inicializa a hash table
    ht = hash_table_create(MAX_SIZE, hash_f);

    // Inicializa o buffer para o gráfico
    initialize_plot(plot);

    while (result != QUIT_){    
        printf(">");
        result = yyparse();
    }

    // Libera a hash table
    hash_table_destroy(ht);

    // Libera a função do plot
    Set_Expre(NULL);
    return 0; 
}

void Set_Expre(TreeNode * expre){
    if (Expre != NULL) Delete_Tree(Expre);
    Expre = expre;
}