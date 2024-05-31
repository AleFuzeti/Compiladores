#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int spill;

typedef struct Node {
    char name[10];
    int init;
    int end;
    struct Node* next;
    int regis;
} Node;

Node* createNode(char* name, int init, int end) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->init = init;
    newNode->end = end;
    newNode->next = NULL;
    newNode->regis = -1;
    return newNode;
}

void insertNode(Node** head, char* name, int init, int end) {
    Node* newNode = createNode(name, init, end);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void iniciaMatriz(int k, int mat[k][3]) {
    for (int i = 0; i < k; i++) {
        mat[i][0] = -1;
        mat[i][1] = -1;
        mat[i][2] = -1;
    }
}

void printSpill(Node* head){
    Node* temp = head;
    while(temp != NULL) {
        if (temp->regis == -1) {
            printf("%s: SPILL\n", temp->name);
        } else {
            printf("%s: %d\n", temp->name, temp->regis);
        }
        temp = temp->next;
    }
}

void AllocRegis(int k, Node* head, char* regis[]) {
    int spills = 0;
    Node* temp = head;
    int mat[k][3];
    int t = 0;

    iniciaMatriz(k, mat);

    while (temp != NULL) {
        int stop = 0;
        
        for (int i = 0; i < k; i++) {
            if (stop == 1) {
                break;
            }
            if (mat[i][2] <= temp->init) {
                mat[i][0] = temp->name;
                mat[i][1] = temp->init;
                mat[i][2] = temp->end;
                temp->regis = i;
                stop = 1;
            }
            
            if (stop == 0 && i == k-1) {
                spill = 1;
                int tam = snprintf(NULL, 0, "%d", t);
                if (spills == 0) {
                    regis[k] = (char *)malloc((tam + 1) * sizeof(char));
                    snprintf(regis[k], tam + 1, "%d", t);
                } else {
                    char *temp_buffer = (char *)malloc((tam + 1) * sizeof(char));
                    snprintf(temp_buffer, tam + 1, "%d", t); 
                    strcat(regis[k], ", ");
                    strcat(regis[k], temp_buffer);
                    free(temp_buffer);
                }
                spills = 1;

                int maior = 0;
                for (int j = 0; j < k; j++) {
                    if (mat[j][2] > mat[maior][2]) {
                        maior = j;
                    } else if (mat[j][2] == mat[maior][2]) {
                        if (mat[j][1] > mat[maior][1]) {
                            maior = j;
                        }else if (mat[j][2] == mat[maior][2] && mat[j][1] == mat[maior][1]) {
                            if (mat[j][0] > mat[maior][0]) {
                                maior = j;
                            }
                        }
                    }
                }
                if(temp->end < mat[maior][2]){
                    
                    Node* temp2 = head;
                    while (temp2 != NULL) {
                        if ((int)temp2->name == mat[maior][0]) {
                            temp2->regis = -1;
                            break;
                        }
                        temp2 = temp2->next;
                    }    
                    mat[maior][0] = temp->name;
                    mat[maior][1] = temp->init;
                    mat[maior][2] = temp->end;
                    temp->regis = maior;
                } else {
                    temp->regis = -1;
                }
            }    
        }
        temp=temp->next;
        t++;
    }

    printSpill(head);
}

/*
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s --> %d %d\n", temp->name, temp->init, temp->end);
        temp = temp->next;
    }
}
*/