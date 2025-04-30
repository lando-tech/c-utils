#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "string_utils.h"


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
    printf("\nArray size: %lu\n", arr->size);
    printf("[");
    for ( i = 0; i < arr->size; ++i )
    {
        printf("%s, ", arr->data[i]);
    }
    printf("]");
    printf("\n");
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

void strip(char *str, char dilim)
{
    int length = strlen(str); 
    int j = 0;
    for ( int i = 0; i < length; ++i )
    {
        if ( str[i] != dilim )
        {
           str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

/*
 * Split the string with '\0'
 * and return the index position of the '\0'
 */
int in_place_split(char *str, char dilim)
{
    int len = strlen(str);
    int i;
    for ( i = 0; i < len; ++i )
    {
        if ( str[i] == dilim )
        {
            str[i] = '\0';
            break;
        }
    }
    return i;
}

int get_token_index(const char *str, const char dilim)
{
    int i;
    for ( i = 0; i < strlen(str); ++i )
    {
        if ( str[i] == dilim )
        {
            return i;
        }
    }
    return -1;
}
