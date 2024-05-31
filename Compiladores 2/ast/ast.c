#include "funcoes.h"
#include "sintatico.tab.h"

extern hash_table* ht;
extern int op_error;
extern float x_expr;
extern int var_n_found;
int handle_op(char left, char right, char op);

TreeNode* Eval_Ast(TreeNode* aux){
    if (aux == NULL) return;
    if (op_error == 1) return;
    TreeNode* esq = Eval_Ast(aux->left);
    TreeNode* dir = Eval_Ast(aux->right);
    int a;

    switch(aux->node_type){
        case INTEGER:
            aux->type = 'f';
            return aux;
            break;
        case PLUS:
            a = handle_op(aux->left->type, aux->right->type, '+');
            //printf("[+] a = %d\n", a);
            if (a == 1) {
                op_error = 1;
                aux->type = 'm';
                aux->value = 0;
                return aux;
            }
            else if (a == 2) {
                aux->type = 'm';
                aux->m = sum_matrix(esq->m, dir->m);
                //matrix_print(aux->m);
                return aux;
            }
            else {
                aux->type = 'f';
                aux->value = esq->value + dir->value;
                return aux;
            }
            break;
        case MINUS:
            a = handle_op(aux->left->type, aux->right->type, '-');
            //printf("[-] a = %d\n", a);
            if (a == 1) {
                op_error = 1;
                aux->type = 'm';
                aux->value = 0;
                return aux;
            }
            else if (a == 2) {
                aux->type = 'm';
                aux->m = sub_matrix(esq->m, dir->m);
                return aux;
            }
            else {
                aux->type = 'f';
                aux->value = esq->value - dir->value;
                return aux;
            }
            break;
        case TIMES:
            a = handle_op(aux->left->type, aux->right->type, '*');
            if(a == 1){
                aux->type = 'm';
                aux->m = mul_n_matrix(esq->m, dir->value);
                return aux;
            } else if (a == 2) {
                aux->type = 'm';
                aux->m = mul_n_matrix(dir->m, esq->value);
                return aux;
            } else if (a == 3) {
                aux->type = 'm';
                aux->m = mul_matrix(esq->m, dir->m);
                return aux;
            } else {
                aux->type = 'f';
                aux->value = esq->value * dir->value;
                return aux;
            }
            break;
        case DIVIDE:
            a = handle_op(aux->left->type, aux->right->type, '/');
            if(a == 1){
                aux->type = 'm';
                aux->m = div_n_matrix(esq->m, dir->value);
                return aux;
            } else if (a == 2|| a == 3) {
                printf("\nIncorrect type for operator '/' - have MATRIX \n\n");
                op_error = 1;
                aux->type == 'f';
                aux->value == 0;
                return aux;
            } else {
                aux->type = 'f';
                aux->value = esq->value / dir->value;
                return aux;
            }
            break;
        case POWER:
            a = handle_op(aux->left->type, aux->right->type, '^');
            if(a == 1 || a == 2 || a == 3){
                printf("\nIncorrect type for operator '^' - have MATRIX\n\n");
                op_error = 1;
                aux->type == 'f';
                aux->value == 0;
                return aux;
            } else {
                aux->type = 'f';
                aux->value = pow(esq->value,dir->value);
                return aux;
            }
            break;
        case SEN:
            if (esq->type == 'm'){
                printf("\nIncorrect type for operator 'SEN' - have MATRIX\n\n");
                op_error = 1;
                aux->type == 'f';
                aux->value == 0;
                return aux;
            }
            aux->type = 'f';
            aux->value = sin(esq->value);
            return aux;
            break;
        case COS:
            if (esq->type == 'm'){
                aux->type == 'f';
                aux->value == 0;
                printf("\nIncorrect type for operator 'COS' - have MATRIX\n\n");
                op_error = 1;
                return aux;
            }
            aux->type = 'f';
            aux->value = cos(esq->value);
            return aux;
            break;
        case TAN:
            if (esq->type == 'm'){
                printf("\nIncorrect type for operator 'TAN' - have MATRIX\n\n");
                aux->type == 'f';
                aux->value == 0;
                op_error = 1;
                return aux;
            }
            aux->type = 'f';
            aux->value = tan(esq->value);
            return aux;
            break;
        case ABS:
            if (esq->type == 'm'){
                aux->type == 'f';
                aux->value == 0;
                op_error = 1;
                printf("\nIncorrect type for operator 'ABS' - have MATRIX\n\n");
                return aux;
            }
            aux->type = 'f';
            aux->value = abs(esq->value);
            return aux;
            break;
        case IDENTIFIER: 
            float num = hash_table_search(ht, aux->name); 
            if (num == NOT_FIND) {
                printf("Undefined symbol [%s]\n", aux->name);
                var_n_found = 1;
            } else 
                aux->type = get_type(ht , aux->name);
                if (aux->type == 'm'){
                    aux->m = get_matrix(ht, aux->name);
                    aux->value = 0;
                } else {
                    if (aux->sinal == 1) {   
                        aux->value = -num;
                        //printf(" [%s = %f] ", aux->name, aux->value);
                        //aux->sinal = 0;
                    } else aux->value = num;
                }
            return aux;
            break;
        case X : 
            aux->type = 'f';
            if (x_expr == 0.0) 
                aux->value = 0;
            else 
                aux->value = x_expr;
            return aux;
            break;
    }
    return aux;
}

int handle_op(char left, char right, char op){
    if (op_error == 1) return 1;
    if (op == '+' || op == '-' ){
        if (left == 'm' && right == 'f'){
            printf("Incorrect type for operator '%c' - have MATRIX and FLOAT\n", op);
            op_error = 1;
            return 1;
        } else if (left == 'f' && right == 'm'){
            printf("Incorrect type for operator '%c' - have FLOAT and MATRIX\n", op);
            op_error = 1;
            return 1;
        } else if (left == 'm' && right == 'm'){
            return 2;
        }
        return 0;
    } else if (op == '*' || op == '/' || op == '^'){
        if (left == 'm' && right == 'f'){
            return 1;
        } else if (left == 'f' && right == 'm'){
            return 2;
        } else if (left == 'm' && right == 'm'){
            return 3;
        }
        return 0;
    }
}

// rpn(sen(x)*(1+x)+chuchu*pi);

void RPN_Walk(TreeNode* aux){
    if (aux == NULL) return;

    RPN_Walk(aux->left);
    RPN_Walk(aux->right);

    switch(aux->node_type){
        case INTEGER: print_formated_number(aux->value,0); printf(" "); break;
        case PLUS: printf("+ "); break;
        case MINUS: printf("- "); break;
        case TIMES:  printf("* "); break;
        case DIVIDE: printf("/ "); break;
        case POWER: printf("^ "); break;
        case SEN:  printf("SEN "); break;
        case COS:  printf("COS "); break;
        case TAN:  printf("TAN "); break;
        case ABS:  printf("ABS "); break;
        case IDENTIFIER: printf("%s ", aux->name); break;
        case X : printf("x "); break;
        default:
            printf("Error ");
            break;
    }
}

void Delete_Tree(TreeNode* aux){
    if (aux == NULL) return;
    Delete_Tree(aux->left);
    Delete_Tree(aux->right);
    free(aux);
}

TreeNode* Create_Node(int type, TreeNode* left, TreeNode* right, float value){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->node_type = type;
    new_node->left = left;
    new_node->right = right;
    new_node->value = value;
    return new_node;
}

float Get_Value(TreeNode* aux) {
    return aux->value;
}

matrix* Get_Matrix(TreeNode* aux) {
    return aux->m;
}

void Set_Name(TreeNode* aux, char* name){
    aux->name = name;
}

void Set_Sinal(TreeNode* aux, int sinal){
    aux->sinal = sinal;
}
