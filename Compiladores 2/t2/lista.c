#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int degree;
extern int spill;

typedef struct Adj {
    int name;
    struct Adj* next;
    int removed;
    int color;
} Adj;

typedef struct Node {
    int name;
    struct Node* next;
    struct Adj* adj;
    int degree;
    int removed;
} Node;

// List functions

Node* createNode(int name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->next = NULL;
    newNode->adj = NULL;
    return newNode;
}

Node* insertNode(Node* head, Adj* adj, int name) {
    Node* newNode = createNode(name);
    newNode->adj = adj;
    newNode->degree = degree;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

Adj* insertAdj(Adj* adj, int name, int color) {
    Adj* newAdj = (Adj*)malloc(sizeof(Adj));
    newAdj->name = name;
    newAdj->next = NULL;
    newAdj->color = color;
    if (adj == NULL) {
        adj = newAdj;
    } else {
        Adj* current = adj;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAdj;
    }
    return adj;
}

Node* normalizeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Adj* adj = current->adj;
        while (adj != NULL) {
            if (adj->removed == 1){
                adj->removed = 0;
                current->degree++;
            }
            adj = adj->next;
        }
        current->removed = 0;
        current = current->next;
    }
    return head;
}

Node* atualizaLista(Node* head, int name){ // se tiver adjacência, decrementa o grau e remove a adjacência
    Node* current = head;
    while (current != NULL){
        if (current->adj != NULL){
            Adj* adj = current->adj;
            while (adj != NULL){
                if (adj->name == name){
                    adj->removed = 1;
                    current->degree--;
                    break;
                }
                adj = adj->next;
            }
        }
        current = current->next;
    }
    return head;
} 

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        Adj* adj = current->adj;
        while (adj != NULL) {
            Adj* nextAdj = adj->next;
            free(adj);
            adj = nextAdj;
        }
        free(current);
        current = next;
    }
}

// Stack functions

Node* push(Node* stack, Node* node){
    Node* new = createNode(node->name);
    new->degree = node->degree;
    new->adj = node->adj;
    if (stack == NULL){
        stack = new;
    } else {
        Node* current = stack;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
    }
    printf("Push: %d", new->name);
    return stack;
}

Node* pop(Node** stack) {
    Node* current = *stack;
    Node* prev = NULL;
    while (current->next != NULL){
        prev = current;
        current = current->next;
    }
    if (prev == NULL){
        *stack = NULL;
    } else {
        prev->next = NULL;
    }
    return current;
}

void achaMenor(Node* head, Node** menor, int* stop) {
    Node* current = head;
    while (current != NULL) {
        if (current->removed == 0){
            if (*menor == NULL){
                *menor = current;
                *stop = 0;
            } else if (current->degree < (*menor)->degree){
                *menor = current;
                *stop = 0;
            } else if (current->degree == (*menor)->degree){
                if (current->name < (*menor)->name){
                    *menor = current;
                    *stop = 0;
                }
            }
        }
        current = current->next;
    }
}

void achaMaior(Node* head, Node** maior) {
    Node* current = head;
    while (current != NULL) {
        if (current->removed == 0){
            if (*maior == NULL){
                *maior = current;
            } else if (current->degree > (*maior)->degree){
                *maior = current;
            }
        }
        current = current->next;
    }
}

Node* montaPilha(Node* stack, Node* head, int k){
    int degree = k;
    int stop = 0;
    while (stop == 0){
        stop = 1;
        Node* menor = NULL;
        Node* maior = NULL;
        achaMenor(head, &menor, &stop);
        if (menor != NULL){
            if (menor->degree >= degree){
                achaMaior(head, &maior);
                maior->removed = 1;
                stack = push(stack, maior);
                printf(" *\n");
                head = atualizaLista(head, maior->name);
            } else {    
                menor->removed = 1;
                stack = push(stack, menor);
                printf("\n");
                head = atualizaLista(head, menor->name);
            }
        }
    }
    return stack;
}

void colorGraph(Node* stack, int k){
    Adj* Color = NULL;
    while(stack){
        int stop = 0;
        Node* node = pop(&stack);
        printf("Pop: %d ->", node->name);

        for (int i = 0; i < k; i++) {   // percorre as cores
            int interferencia = 0;
            if (stop == 1){
                break;
            }

            Adj* adj = node->adj;   
            while (adj != NULL){      // percorre adjacencia
                Adj* color = Color;   
                if(adj->name == i) {   // se a cor ta na adjacencia
                    interferencia = 1;
                }
                while(color != NULL){
                    if(color->name == adj->name && color->color == i ){ // se um no ja colorido com a cor ta na adjacencia
                        interferencia = 1;
                    }
                    color=color->next;
                }
                adj=adj->next;
            }  
            if(interferencia==0){
                Color = insertAdj(Color, node->name, i);
                printf(" %d", i);
                stop = 1;
            }    
            if(i==k-1 && interferencia==1){
                printf(" NO COLOR AVAILABLE\n");
                spill=1;
                return;
            }
        }
        if(stack){
            printf("\n");
        }
    }
    printf("\n");
}

void freeStack(Node* stack){
    Node* current = stack;
    while (current != NULL){
        Node* next = current->next;
        free(current);
        current = next;
    }
}

/*
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->name);
        if (current->adj != NULL) {
            printf("(%d) ", current->degree);
            printf("--> ");
            Adj* adj = current->adj;
            while (adj != NULL) {
                if (adj->removed == 0){
                    printf("%d ", adj->name);
                }
                adj = adj->next;
            }
        }
        printf("\n");
        current = current->next;
    }
    printf("\n");
}

void displayStack(Node* stack){
    Node* current = stack;
    printf("Pilha: ");
    while (current != NULL){
        printf("%d ", current->name);
        current = current->next;
    }
    printf("\n");
}
*/

