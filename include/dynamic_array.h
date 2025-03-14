#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct
{
    char **data;
    size_t size;
    size_t capacity;
} StringArray;

StringArray* create_array(size_t capacity);
void free_array(StringArray *arr);
void append(StringArray *arr, char *element);
// int get_element(DynamicArray *arr, int index);
void print_array(StringArray *arr);

#endif // DYNAMIC_ARRAY_H
