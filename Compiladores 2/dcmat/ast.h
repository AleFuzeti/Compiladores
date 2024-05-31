#ifndef AST_H
#define AST_H
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "hash.h"
//#include "funcoes.h"

typedef struct node TreeNode;

struct node {
    int node_type;
    float value;
    char* name;
    TreeNode* left;
    TreeNode* right;
    char type;
    matrix* m;
    int sinal;
};

void RPN_Walk(TreeNode* aux);
//float AST_Walk(TreeNode* aux);
TreeNode* Eval_Ast(TreeNode* aux);
void Delete_Tree(TreeNode* aux);
TreeNode* Create_Node(int type, TreeNode* left, TreeNode* right, float value);
float Get_Value(TreeNode* aux);
void Set_Name(TreeNode* aux, char* name);
void Set_Sinal(TreeNode* aux, int sinal);
#endif