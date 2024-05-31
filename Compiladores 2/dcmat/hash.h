#ifndef HASH_H
#define HASH_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 9997
#define NOT_FIND -558215

typedef struct matrix matrix;

typedef uint64_t hash_function(const char*, size_t);
uint64_t hash_f(const char* key, size_t len);
typedef struct _hash_table hash_table;

hash_table* hash_table_create(uint32_t size, hash_function* hf);
void hash_table_destroy(hash_table* ht);
void hash_table_print(hash_table* ht);
bool hash_table_insert(hash_table* ht, const char* key, float value);
float hash_table_search(hash_table* ht, const char* key);
char get_type(hash_table* ht, const char* key);
matrix* get_matrix(hash_table* ht, const char* key);
float hash_table_remove(hash_table* ht, const char* key);

#endif