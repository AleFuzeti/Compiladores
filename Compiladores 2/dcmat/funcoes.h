#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "hash.h"
#include "ast.h"


void About();
void ShowSettings();
void ResetSettings();
float integral_ast(TreeNode* expr, float lower_limit, float upper_limit, int num_subintervals);


// Funções do plot
void initialize_plot(char plot[HEIGHT][WIDTH]);
void print_plot(char plot[HEIGHT][WIDTH]);
void plot_function(char plot[HEIGHT][WIDTH], TreeNode* Expre);

// Funções da matriz
typedef struct matrix matrix;
matrix* matrix_grammar(char* buffer, char* name, hash_table* ht);
float matrix_determinant(matrix* mat);
void solve_linear_system(matrix* mat);

matrix* sum_matrix(matrix* mat1, matrix* mat2);
matrix* sub_matrix(matrix* mat1, matrix* mat2);
matrix* mul_n_matrix(matrix* mat, float num);
matrix* div_n_matrix(matrix* mat, float num);
matrix* mul_matrix(matrix* mat1, matrix* mat2);
matrix* minus_mat (matrix* mat);

void matrix_print(matrix* m);
bool htable_insert_matrix(hash_table* ht, const char*  key , matrix* m);

print_formated_number(float number, int n1);