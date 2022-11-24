#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifndef DATASTRUCTS_DATA_T
#define DATASTRUCTS_DATA_T
typedef uint64_t Data;
#endif // DATASTRUCTS_DATA_T

#ifndef DATASTRUCTS_VECTOR_H
#define DATASTRUCTS_VECTOR_H

typedef struct Vector {
	size_t size; // amount of storage space in the Vector
	size_t len;  // largest occupied index in Vector
	Data *array; // pointer to the storage space
	bool *used;  // pointer to the "is used" storage space
} Vector;

Vector *new_Vector(size_t size);
void del_Vector(Vector *v);
Vector *copy_Vector(Vector *v);

Data *at_Vector(Vector *v, size_t index);
void insert_Vector(Vector *v, Data d, size_t index);
void resize_Vector(Vector *v, size_t size);
void remove_Vector(Vector *v, size_t index);
void clear_Vector(Vector *v);

void print_Vector(Vector *v);

#endif // VECTOR_H