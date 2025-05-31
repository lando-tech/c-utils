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

StringArray* str_array_init(size_t capacity);
void str_array_free(StringArray *arr);
void str_array_append(StringArray *arr, char *element);
void str_array_pop(StringArray *arr);
void str_array_print(StringArray *arr);


int get_token_index(const char *str, const char dilim);
void strip(char *str, char dilim);
int in_place_strip(const char *str, const char dilim);

#endif
