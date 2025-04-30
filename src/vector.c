#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

/*
 * Dynamic vector, with void** data type
 *
 */
Vector* vector_init(size_t capacity)
{
    if (capacity == 0) capacity = 10;
    Vector *vec = malloc(sizeof(Vector));
    vec->data = malloc(sizeof(char *) * capacity);
    vec->size = 0;
    vec->capacity = capacity;
    return vec;
}

void vector_append(Vector *vec, void *element)
{
    char *new_elem = strdup(element);
    if ( vec->size == vec->capacity )
    {
        vec->capacity *= 2;
        char **temp = realloc(vec->data, sizeof(char *) * vec->capacity);
        if (temp != NULL)
        {
            vec->data = temp;
            vec->data[arr->size] = new_elem;
            vec->size++;
        }
        else
        {
            printf("Unable to reallocate memory!\n");
            free(new_elem);
            return;
        }
    }
    else if ( vec->size < vec->capacity )
    {
        vec->data[vec->size] = new_elem;
        vec->size++;
    }
}

void vector_pop(Vector *vec)
{
    if ( vec->size == 0 )
    {
        perror("Array has no elements to remove");
        return;
    }
    free(vec->data[vec->size - 1]);
    vec->size--;

    if ( vec->size < vec->capacity / 4 && vec->capacity > 5 )
    {
        vec->capacity /= 2;
        void **new_data = realloc(vec->data, sizeof(void *) * vec->capacity);

        if ( new_data ) vec->data = new_data;
    }
}

void vector_print(Vector *vec)
{
    int i;
    printf("\nArray size: %lu\n", vec->size);
    for ( i = 0; i < vec->size; ++i )
    {
        printf(" %s", vec->data[i]);
    }
    printf("\n");
}

void vector_free(Vector *vec)
{
    for ( size_t i = 0; i < vec->size; ++i )
    {
        free(vec->data[i]);
    }
    free(vec->data);
    free(vec);
}
