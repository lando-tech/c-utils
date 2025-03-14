#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/dynamic_array.h"


/*
 * Dynamic array for strings, can be easily altered to fit
 * any data type
 */
StringArray* create_array(size_t capacity)
{
    if (capacity == 0) capacity = 1;
    StringArray *arr = malloc(sizeof(StringArray));
    arr->data = malloc(sizeof(char *) * capacity);
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void append(StringArray *arr, char *element)
{
    char *new_elem = strdup(element);
    if ( arr->size == arr->capacity )
    {
        arr->capacity *= 2;
        char **temp = realloc(arr->data, sizeof(char *) * arr->capacity);
        if (temp != NULL)
        {
            arr->data = temp;
            arr->data[arr->size] = new_elem;
            arr->size++;
        }
        else
        {
            perror("Unable to reallocate memory!\n");
            free(new_elem);
            return;
        }
    }
    else if ( arr->size < arr->capacity )
    {
        arr->data[arr->size] = new_elem;
        arr->size++;
    }
}

void pop(StringArray *arr)
{
    if ( arr->size == 0 )
    {
        perror("Array has no elements to remove");
        return;
    }
    free(arr->data[arr->size - 1]);
    arr->size--;

    if ( arr->size < arr->capacity / 4 && arr->capacity > 5 )
    {
        arr->capacity /= 2;
        char **new_data = realloc(arr->data, sizeof(char *) * arr->capacity);

        if ( new_data ) arr->data = new_data;
    }
}

void print_array(StringArray *arr)
{
    int i;
    printf("\nArray size: %d\n", arr->size);
    for ( i = 0; i < arr->size; ++i )
    {
        printf(" %s", arr->data[i]);
    }
    printf("\n");
}

int array_size(StringArray *arr)
{
    return arr->size;
}

void free_array(StringArray *arr)
{
    for ( size_t i = 0; i < arr->size; ++i )
    {
        free(arr->data[i]);
    }
    free(arr->data);
    free(arr);
}
