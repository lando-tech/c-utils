#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct Vector
{
    void** data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_init(size_t capacity);
void vector_free(Vector *vec);
void vector_append(Vector *vec, char *element);
void vector_pop(Vector *vec);
void vector_print(Vector *vec);

#endif
