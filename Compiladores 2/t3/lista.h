#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct
typedef struct Node Node;

// Function to create a new node
Node* createNode(char* name, int init, int end);

// Function to insert a node at the end of the list
void insertNode(Node** head, char* name, int init, int end);

// Function to display the linked list
void displayList(Node* head);

void freeList(Node* head);

void AllocRegis(int k, Node* head, char* regis[]);
