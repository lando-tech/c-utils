#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stdint.h>
#include <stdlib.h>

/*
 * String array that resizes itself dynamically
 */
typedef struct
{
    char **data;
    size_t size;
    size_t capacity;
} StringArray;

StringArray* create_array(size_t capacity);
void free_array(StringArray *arr);
void append(StringArray *arr, char *element);
void pop(StringArray *arr);
void print_array(StringArray *arr);


int get_token_index(const char *str, const char dilim);
void strip(char *str, char dilim);
int in_place_strip(const char *str, const char dilim);

#endif
