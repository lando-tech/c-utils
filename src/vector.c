#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../include/vector.h"

Vector* vector(DataTypes dtype)
{
    Vector *vec = malloc(sizeof(Vector));
    vec->capacity = 10;
    vec->size = 0;

    switch (dtype)
    {
    case STRING:
        vec->data = malloc(sizeof(char *) * vec->capacity);
        break;
    case INT:
        vec->data = malloc(sizeof(int *) * vec->capacity);
        break;
    case DOUBLE:
        vec->data = malloc(sizeof(double *) * vec->capacity);
        break;
    case LONG_INT:
        vec->data = malloc(sizeof(long int *) * vec->capacity);
        break;
    case LONG_DOUBLE:
        vec->data = malloc(sizeof(long double *) * vec->capacity);
        break;
    case U_INT:
        vec->data = malloc(sizeof(unsigned int *) * vec->capacity);
        break;
    case U_LONG_INT:
        vec->data = malloc(sizeof(unsigned long int *) * vec->capacity);
        break;
    default: perror("Must specify data type"); break;
    }
    return vec;
}

void vec_append(Vector *vector, void **data);
