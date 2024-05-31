#include "funcoes.h"
#include "hash.h"
#include "ast.h"
#include "sintatico.tab.h"
#include <math.h>

extern int float_precision;
extern float h_view_lo;
extern float h_view_hi;
extern float v_view_lo;
extern float v_view_hi;
extern int integral_steps;
extern int draw_axis;
extern int erase_plot;
extern int connect_dots;
extern float x_expr;
extern int op_error;
extern int var_n_found;

extern TreeNode* Expre;

// General functions
void About(){
    printf("\n");
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|                202100560218                  |\n");
    printf("|        Alexandre Fuzeti Bertipaglia          |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n");
    printf("\n");
}

void ShowSettings(){
    printf("\n");
    printf("h_view_lo: %f\n", h_view_lo);
    printf("h_view_hi: %f\n", h_view_hi);
    printf("v_view_lo: %f\n", v_view_lo);
    printf("v_view_hi: %f\n", v_view_hi);
    printf("float_precision: %d\n", float_precision);
    printf("integral_steps: %d\n", integral_steps);
    printf("\n");
    if (draw_axis == 1){
        printf("draw_axis: ON\n");
    } else {
        printf("draw_axis: OFF\n");
    }
    if (erase_plot == 1){
        printf("erase_plot: ON\n");
    } else {
        printf("erase_plot: OFF\n");
    }
    if (connect_dots == 1){
        printf("connect_dots: ON\n");
    } else {
        printf("connect_dots: OFF\n");
    }
    printf("\n");

}

void ResetSettings() {
    h_view_lo = H_VIEW_LO_;
    h_view_hi = H_VIEW_HI_;
    v_view_lo = V_VIEW_LO_;
    v_view_hi = V_VIEW_HI_;
    float_precision = FLOAT_PRECISION;
    integral_steps = INTEGRAL_STEPS__;
    draw_axis = DRAW_AXIS;
    erase_plot = ERASE_PLOT;
    connect_dots = CONNECT_DOTS_;
}

float integral_ast_esquerda(TreeNode* expr, float lower_limit, float upper_limit, int num_subintervals) {
    float integral = 0.0;
    float delta_x = (upper_limit - lower_limit) / num_subintervals;
    for (int i = 0; i < num_subintervals; i++) {
        float x_left = lower_limit + i * delta_x;
        // Avalia a árvore da expressão em x_left
        x_expr = x_left;
        float y = Get_Value(Eval_Ast(expr));
        integral += y * delta_x;
        if(op_error || var_n_found) return 0;
    }
    x_expr = 0.0;
    return integral;
}

float integral_ast_direita(TreeNode* expr, float lower_limit, float upper_limit, int num_subintervals) {
    if(op_error || var_n_found) return 0;
    float integral = 0.0;
    float delta_x = (upper_limit - lower_limit) / num_subintervals;
    for (int i = 1; i <= num_subintervals; i++) {
        float x_right = lower_limit + i * delta_x;
        // Avalia a árvore da expressão em x_right
        x_expr = x_right;
        float y = Get_Value(Eval_Ast(expr));
        integral += y * delta_x;
    }
    x_expr = 0.0;
    return integral;
}

float integral_ast(TreeNode* expr, float lower_limit, float upper_limit, int num_subintervals) {
    float esq = integral_ast_esquerda(expr, lower_limit, upper_limit, num_subintervals);
    float dir = integral_ast_direita(expr, lower_limit, upper_limit, num_subintervals);
    return esq+dir;
}

// Matrix functions
typedef struct matrix{
    int rows;
    int cols;
    float* data;
} matrix;

matrix* matrix_create(int rows, int cols){
    matrix* m = malloc(sizeof(*m));
    m->rows = rows;
    m->cols = cols;
    m->data = calloc(sizeof(float)*rows*cols, rows*cols);
    return m;
}

void matrix_destroy(matrix* m){
    free(m->data);
    free(m);
}

int num_digits(float num){
     int num_abs = abs((int)num);
            int num_digits = 0;
            while (num_abs > 0) {
                num_abs /= 10;
                num_digits++;
            }
            
            if (num_digits >0) num_digits += -1;
            return num_digits;
}

int* calcula_posicoes(matrix * m){
    int* vetor = malloc(sizeof(int) * m->cols);
    int esp;

    for (int j = 0; j < m->cols; j++) {      
        esp = 0;
        for (int i = 0; i < m->rows; i++) {     
            float num = m->data[i * m->cols + j];
            //printf("num: %f ", num);
            int aux = num_digits(num);
            if (num < 0) aux++;
            if (aux > esp) esp = aux;
        }
        //printf("esp: %d\n ", esp);
        vetor[j] = esp;
    }
    return vetor;
}

void matrix_print(matrix* m){
    if (m == NULL) return;
    int* vet = calcula_posicoes(m);
    int esp = 0;
    for (int i = 0; i < m->cols; i++) {
        esp += vet[i];
    }
    int a = m->cols*float_precision; // precisão
    int b = m->cols*2; // primeiro digito e '.'
    if (float_precision == 0) b =+ m->cols;
    int c = m->cols-1;  // espaço entre os numeros

    printf("\n+-");
    for(int i = 0; i < a + b + c + esp; i++){
        printf(" ");
    }
    printf("-+\n");
    for(int i = 0; i < m->rows; i++){
        printf("| ");
        for(int j = 0; j < m->cols; j++){
            float num = m->data[i*m->cols+j];
            int esp2 = vet[j] - num_digits(num);
            if (num<0) esp2--;
            //printf("v:%d ", vet[j]);
            //printf(" d:%d ", num_digits(num));
            //printf(" e2:%d ", esp2);
            for(int k = 0; k < esp2; k++) {
                printf(" ");
                //printf("+");
            }
            print_formated_number(num, 0);
            printf(" ");
        }
        printf("|\n");
    }
    printf("+-");
    for(int i = 0; i < a + b + c + esp; i++){
        printf(" ");
    }
    printf("-+\n\n");
}

// matrix= [[1,1.3,8],[2,2,16]];
matrix* matrix_grammar(char *buffer, char* name, hash_table* ht) {
    float mat[MAX_ROWS][MAX_COLS] = {{0.0}}; // Inicializa a matriz com zeros

    char *ptr = strstr(buffer, "["); // Encontra o início da matriz
    if (ptr == NULL) {
        printf("Matriz não encontrada na string.\n");
        return;
    }

    int row = 0, col = 0, k = 0;
    ptr += 1; 
    while (*ptr != ']') {
        if (*ptr == ' ') {
            ptr++;
            continue;
        }
        if (*ptr == '[') {
            k = 0;
            ptr++;
            while (*ptr != ']') {
                if (*ptr == ' ') {
                    ptr++;
                    continue;
                }
                if (*ptr == ',') {
                    ptr++;
                    continue;
                }
                if (*ptr == '.'){
                    printf("ponto");
                }
                char* num = (char*)malloc(10 * sizeof(char));
                int i = 0;
                while (*ptr != ' ' && *ptr != ',' && *ptr != ']') {
                //    printf("ptr: %c ", *ptr);
                    num[i++] = *ptr++;
                }
                mat[row][k] = atof(num);
                //printf("mat[%d][%d] = %f\n", row, col, mat[row][col]);
                k++;
                if (k > col) col = k;
                free(num);

            }
            ptr++;
        }
        if (*ptr == ',') {
            ptr++;
            row++;
        }
        if (col>=MAX_COLS || row>=MAX_ROWS) {
            printf("\nERROR: Matrix limits out of boundaries.\n\n");
            return;
        }
    }
    row++;

    matrix* math = matrix_create(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            math->data[i*col+j] = mat[i][j];
        }
    }
    //matrix_print(math);
    if (strcmp(name, "matrix") != 0) {
        hash_table_insert_matrix(ht, name, *math);
    }
    return math;
}

float matrix_determinant(matrix* mat) {
    // Verifica se a matriz é quadrada
    if (mat->rows != mat->cols) {
        printf("\nMatrix format incorrect!\n\n"); return NOT_FIND;
    }
    float det = 1;
    float temp;
    int n = mat->rows;
    for (int i = 0; i < n; i++) {
        // Encontra o pivot
        int pivot_row = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(mat->data[j*n+i]) > fabs(mat->data[pivot_row*n+i])) {
                pivot_row = j;
            }
        }

        // Troca as linhas se necessário
        if (pivot_row != i) {
            for (int j = 0; j < n; j++) {
                temp = mat->data[i*n+j];
                mat->data[i*n+j] = mat->data[pivot_row*n+j];
                mat->data[pivot_row*n+j] = temp;
            }
            det *= -1; // Troca de linha troca o sinal do determinante
        }

        // Eliminação de Gauss
        for (int j = i + 1; j < n; j++) {
            if (mat->data[i*n+i] == 0) return 0;
            temp = mat->data[j*n+i] / mat->data[i*n+i];
            for (int k = i; k < n; k++) {
                mat->data[j*n+k] -= temp * mat->data[i*n+k];
            }
        }

        // Multiplica o determinante pelo elemento diagonal atual
        det *= mat->data[i*n+i];
    }
    return det;
}

// matrix= [[10,2,1,7],[1,5,1,-8],[2,3,10,6]];
// matrix= [[10,2,1],[1,5,1],[2,3,10]];
// matrix= [[1,1,8],[2,2,16]];
// matrix= [[3,2,6],[3,2,12]];

// solve linear_system;
void solve_linear_system(matrix* mat) {
    // Verifica se a matriz é aumentada
    if (mat->rows != mat->cols - 1) {
        printf("\nMatrix format incorrect!\n\n"); 
        return;
    }

    // matrix_print(mat);

    // Declarações
    int n = mat->rows;
    float A[n][n];
    float B[n];
    matrix* a = matrix_create(n, n);

    // Separa a matriz A e o vetor B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = mat->data[i * (n + 1) + j]; // A matriz mat é aumentada, então adicionamos 1 a n
        }
        B[i] = mat->data[i * (n + 1) + n]; // A última coluna é a coluna n
    }
    // cria a matriz a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a->data[i*n+j] = A[i][j];
        }
    }
    // matrix_print(a);

    // // Printa a matriz A
    // printf("\nMatrix A:\n\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%f ", A[i][j]);
    //     }
    //     printf("\n");
    // }

    // // Printa a matriz B
    // printf("\nMatrix B:\n\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%f\n", B[i]);
    // }

    // Escalonamento
    for(int k=0; k < n; k++){
        float pivot =  A[k][k];
        int l_pivot = k;
        for (int i = k+1; i < n; i++){
            if (fabs(A[i][k]) > fabs(pivot)){
                pivot = A[i][k];
                l_pivot = i;
            }
        }
        if (l_pivot != k){
            for (int j = 0; j < n; j++){
                float temp = A[k][j];
                A[k][j] = A[l_pivot][j];
                A[l_pivot][j] = temp;
            }
            float temp = B[k];
            B[k] = B[l_pivot];
            B[l_pivot] = temp;
        }
        for (int i = k+1; i < n; i++){
            float m = A[i][k]/A[k][k];
            for (int j = k; j < n; j++){
                A[i][j] = A[i][j] - m*A[k][j];
            }
            B[i] = B[i] - m*B[k];
        }
    }

    // Substituição retroativa
    float X[n];
    for (int i = n-1; i >= 0; i--){
        X[i] = B[i];
        for (int j = i+1; j < n; j++){
            X[i] = X[i] - A[i][j]*X[j];
        }
        X[i] = X[i]/A[i][i]; 
        // printf("X[%d] = %f\n", i, X[i]);
        if (isnan(X[i])) {
            printf("\nSPI - The Linear System has infinitely many solutions\n\n");
            return;
        }
        if (isinf(X[i])) {
            printf("\nSI - The Linear System has no solution\n\n");
            return;
        } 
    }
    printf("\nMatrix x:\n\n");
    for (int i = 0; i < n; i++){
        printf("%f\n", X[i]);
    }
    printf("\n");
    matrix_destroy(a);
}

matrix* sum_matrix(matrix* mat1, matrix* mat2){
    //if (mat1 == NULL || mat2 == NULL) return NULL;
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("\nIncorrect dimensions for operator '+' - have MATRIX [%d][%d] and MATRIX [%d][%d]\n\n", mat1->rows, mat1->cols, mat2->rows, mat2->cols); 
        op_error = 1; return NULL;
    }
    matrix* sum = matrix_create(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            sum->data[i*mat1->cols+j] = mat1->data[i*mat1->cols+j] + mat2->data[i*mat1->cols+j];
        }
    }
    return  sum;
}

matrix* sub_matrix(matrix* mat1, matrix* mat2){
    //if (mat1 == NULL || mat2 == NULL) return NULL;
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("\nIncorrect dimensions for operator '-' - have MATRIX [%d][%d] and MATRIX [%d][%d]\n\n", mat1->rows, mat1->cols, mat2->rows, mat2->cols); 
        op_error = 1; return NULL;
    }
    matrix* sub = matrix_create(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            sub->data[i*mat1->cols+j] = mat1->data[i*mat1->cols+j] - mat2->data[i*mat1->cols+j];
        }
    }
    return sub;
}

matrix* mul_n_matrix(matrix* mat, float num){
    if (mat == NULL) return NULL;
    matrix* mul = matrix_create(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mul->data[i*mat->cols+j] = mat->data[i*mat->cols+j] * num;
        }
    }
    return mul;
}

matrix* div_n_matrix(matrix* mat, float num){
    if (mat == NULL) return NULL;
    matrix* div = matrix_create(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            div->data[i*mat->cols+j] = mat->data[i*mat->cols+j] / num;
        }
    }
    return div;
}

matrix* mul_matrix(matrix* mat1, matrix* mat2){
    if (mat1->cols != mat2->rows) {
        printf("\nIncorrect dimensions for operator '*' - have MATRIX [%d][%d] and MATRIX [%d][%d]\n\n", mat1->rows, mat1->cols, mat2->rows, mat2->cols);
        op_error = 1; return NULL;
    }
    printf("mat1->cols: %d, mat2->rows: %d\n", mat1->cols, mat2->rows);

    matrix* mul = matrix_create(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            for (int k = 0; k < mat1->cols; k++) {
                mul->data[i*mat2->cols+j] += mat1->data[i*mat1->cols+k] * mat2->data[k*mat2->cols+j];
            }
        }
    }
    return mul;
}

matrix* minus_mat (matrix* mat){
    if (mat == NULL) return NULL;
    matrix* minus = matrix_create(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            minus->data[i*mat->cols+j] = -mat->data[i*mat->cols+j];
        }
    }
    return minus;
}

int Get_Rows(matrix* m){
    return m->rows;
}

int Get_Cols(matrix* m){
    return m->cols;
}

// Funções do plot
void initialize_plot(char plot[HEIGHT][WIDTH]) {
    // Inicializa o buffer com espaços em branco
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            plot[i][j] = ' ';
        }
    }
}

void print_plot(char plot[HEIGHT][WIDTH]) {
        if (draw_axis) {
                // Desenha os eixos X e Y
                for (int i = 0; i < WIDTH; i++) {
                    if (plot[(HEIGHT - 1) / 2][i] != '*')
                    plot[(HEIGHT - 1) / 2][i] = '-';  // Eixo X
                }

                for (int i = 0; i < HEIGHT; i++) {
                    if (plot[i][(WIDTH- 1) / 2] != '*')
                    plot[i][(WIDTH- 1) / 2] = '|';  // Eixo Y
                }
            }
        else {
            // Remove os eixos X e Y
            for (int i = 0; i < WIDTH; i++) {
                if (plot[(HEIGHT - 1) / 2][i] == '-')
                plot[(HEIGHT - 1) / 2][i] = ' ';  // Eixo X
            }
            for (int i = 0; i < HEIGHT; i++) {
                if (plot[i][(WIDTH - 1) / 2] == '|')
                plot[i][(WIDTH - 1) / 2] = ' ';  // Eixo Y
            }
        }
    // Imprime o gráfico
    for (int i = 0; i < HEIGHT; i++) {
        //for (int j = WIDTH-1; j >= 0; j--) {
        for (int j = 0; j < WIDTH-1;  j++) {
            printf("%c", plot[i][j]);
        }
        printf("\n");
    }
    
}

void plot_function(char plot[HEIGHT][WIDTH], TreeNode* Expre) {
    // Calcula e desenha a função no gráfico
    if (erase_plot) {
        initialize_plot(plot);
    }
    
    // Loop para iterar pelo intervalo de visualização horizontal
    for (int col = 0; col < WIDTH; col++) {
        // Calcula o valor de "x" no intervalo de visualização
        float x = h_view_lo + (col / (float)(WIDTH - 1)) * (h_view_hi - h_view_lo);
        
        // Substitui "x" na expressão pelo valor atual
        x_expr = x;
        
        // Avalia a expressão com a variável substituída
        float value = Get_Value(Eval_Ast(Expre));
        //printf("x: %f, y: %f\n", x, value);
        
        // Ajuste para o intervalo [0, HEIGHT - 1]
        int pixel_value = (int)((v_view_hi - value) / (v_view_hi - v_view_lo) * (HEIGHT - 1) ) ;
        
        // Desenha '*' se estiver perto do valor da função
        if (pixel_value >= 0 && pixel_value < HEIGHT) {
            plot[pixel_value][col] = '*';
        }
    }
    x_expr = 0.0;
    print_plot(plot);
}

print_formated_number(float value, int n1) {
    if (n1) printf("\n");
    printf("%.*f", float_precision, value);
    if (n1) printf("\n");
}