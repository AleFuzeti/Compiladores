#include "hash.h"

typedef struct matrix{
    int rows;
    int cols;
    float* data;
} matrix;

typedef struct _hash_node{
    char* key;
    float value;
    char type;
    matrix m;
    struct _hash_node* next;
} hash_node;

typedef struct _hash_table{
    uint32_t size;
    hash_function* hf;
    hash_node** elements;
} hash_table;

int get_cols(matrix* m){
    return m->cols;
}

int get_rows(matrix* m){
    return m->rows;
}

static size_t hash_table_index(hash_table* ht, const char* key){
    size_t hash = ht->hf(key, strlen(key)) % ht->size;
    return hash;
}

hash_table* hash_table_create(uint32_t size, hash_function* hf){
    hash_table* ht = malloc(sizeof(*ht));
    ht->size = size;
    ht->hf = hf;
    ht->elements = calloc(sizeof(hash_node*)*size, ht->size);
    return ht;
}

void hash_table_destroy(hash_table* ht){
    //printf("Destroying table\n");
    for(uint32_t i = 0; i < ht->size; i++){
        hash_node* node = ht->elements[i];
        while(node){
            hash_node* next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(ht->elements);
    free(ht);

}

void hash_table_print(hash_table* ht){
    printf("\n");
    for(uint32_t i = 0; i < ht->size; i++){
        if  (ht->elements[i] != NULL){
            hash_node* node = ht->elements[i];
            //printf("\tKey\t| Value\n");
            while  (node){
                if (node->type == 'f') printf("%s - FLOAT ", node->key, node->value);
                if (node->type == 'm') printf("%s - MATRIX [%d][%d]", node->key, get_cols(&node->m), get_rows(&node->m));
                node = node->next;
            }
            //printf("\nAAAAAAAAAA");
            printf("\n");
        } else {
           // printf("%i\t\n", i); // Empty
        }
    }
    printf("\n");
}

bool hash_table_insert(hash_table* ht, const char*  key , float value){
    if (key == NULL) return false;
    size_t index = hash_table_index(ht, key);
    if (hash_table_search(ht, key) != NOT_FIND) {
        hash_table_remove(ht, key);
    }
    //printf("value: %f\n", value);
    // Create new node
    hash_node* node = malloc(sizeof(*node));
    node->type = 'f';
    node->value = value;
    node->key = malloc(strlen(key)+1);
    strcpy(node->key, key);

    // Insert node
    node->next = ht->elements[index];
    ht->elements[index] = node;
    return true;
}

bool hash_table_insert_matrix(hash_table* ht, const char*  key , matrix m){
    if (key == NULL) return false;
    size_t index = hash_table_index(ht, key);
    if (hash_table_search(ht, key) != NOT_FIND) {
        hash_table_remove(ht, key);
    }

    // Create new node
    hash_node* node = malloc(sizeof(*node));
    node->type = 'm';
    node->m = m;
    node->key = malloc(strlen(key)+1);
    strcpy(node->key, key);

    // Insert node
    node->next = ht->elements[index];
    ht->elements[index] = node;
    return true;
}

bool htable_insert_matrix(hash_table* ht, const char*  key , matrix*m){
    if (key == NULL) return false;
    size_t index = hash_table_index(ht, key);
    if (hash_table_search(ht, key) != NOT_FIND) {
        hash_table_remove(ht, key);
    }

    // Create new node
    hash_node* node = malloc(sizeof(*node));
    node->type = 'm';
    node->m = *m;
    node->key = malloc(strlen(key)+1);
    strcpy(node->key, key);

    // Insert node
    node->next = ht->elements[index];
    ht->elements[index] = node;
    return true;

}

float hash_table_search(hash_table* ht, const char* key){
    if (key == NULL || ht == NULL) return false;
    size_t index = hash_table_index(ht, key);

    hash_node* node = ht->elements[index];
    while(node &&  strcmp(node->key, key) != 0){
        node = node->next;
    }
    if (node) return node->value;
    return NOT_FIND; // Not found
}

float hash_table_remove(hash_table* ht, const char*  key){
    if (key == NULL || ht == NULL) return false;
    size_t index = hash_table_index(ht, key);

    hash_node* node = ht->elements[index];
    hash_node* prev = NULL;
    while(node &&  strcmp(node->key, key) != 0){
        prev = node;
        node = node->next;
    }
    if (node){
        if (prev){ // Not first element
            prev->next = node->next;
        } else { // First element
            ht->elements[index] = node->next;
        }
        float value = node->value;
        free(node->key);
        free(node);
        return value;   
    }
    return NOT_FIND; // Not found
}

char get_type(hash_table* ht, const char* key){
    if (key == NULL || ht == NULL) return false;
    size_t index = hash_table_index(ht, key);

    hash_node* node = ht->elements[index];
    while(node &&  strcmp(node->key, key) != 0){
        node = node->next;
    }
    if (node) return node->type;
    return NOT_FIND; // Not found
}

matrix* get_matrix(hash_table* ht, const char* key){
    if (key == NULL || ht == NULL) return NULL;
    size_t index = hash_table_index(ht, key);

    hash_node* node = ht->elements[index];
    while(node &&  strcmp(node->key, key) != 0){
        node = node->next;
    }
    if (node) return &node->m;
    return NULL; // Not found
}

void get_print_matrix(hash_table* ht, const char* key){
    if (key == NULL || ht == NULL) return NULL;
    size_t index = hash_table_index(ht, key);

    hash_node* node = ht->elements[index];
    while(node &&  strcmp(node->key, key) != 0){
        node = node->next;
    }
    if (node) matrix_print(&node->m);
    return NULL; // Not found
}
// Hash function
uint64_t hash_f(const char* key, size_t len){
    uint64_t hash = 0;
    for(int i = 0; i < len; i++){
        hash += key[i];
        hash = hash * key[i];
    }
    return hash;
}
