#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct
typedef struct Node Node;
typedef struct Adj Adj;

// Function to create a new node
Node* createNode(int name);

// Function to insert a node at the end of the list
Node* insertNode(Node* head, Adj* adj, int name) ;

Adj* insertAdj(Adj* adj, int name, int color);

void freeList(Node* head);

Node* normalizeList(Node* head);

Node* montaPilha(Node* stack, Node* head, int k);

//void displayStack(Node* stack);

//void displayList(Node* head);