#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#include "string_utils.h"

// TODO utilize INITIAL_CAPACITY constant from string_utils.h
StringArray* str_array_init(size_t capacity)
{
    // Ensure capacity is set in case the caller passes in 0
    if (capacity == 0) capacity = 24; // Resizing is expensive, so a larger buffer is used
    StringArray *arr = malloc(sizeof(StringArray));
    if (arr == NULL)
    {
        printf("Failed to initialize StringArray!\n");
        return NULL;
    }

    arr->data = malloc(sizeof(char *) * capacity);
    if (arr->data == NULL)
    {
        printf("Failed to initialize StringArray!\n");
        return NULL;
    }
    // Array is empty, size = 0
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void str_array_append(StringArray *arr, char *element)
{
    char *new_elem = strdup(element);
    // Size has reached capacity, resize the array
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
            printf("Unable to reallocate memory!\n");
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

void str_array_pop(StringArray *arr)
{
    if ( arr->size == 0 )
    {
        printf("Array has no elements to remove!\n");
        return;
    }
    free(arr->data[arr->size - 1]);
    arr->size--;

    if ( arr->size < arr->capacity / 4 && arr->capacity > 5 )
    {
        arr->capacity /= 2;
        char **new_data = realloc(arr->data, sizeof(char *) * arr->capacity);

        if ( new_data ) arr->data = new_data;
        else printf("Failed to resize String Array!\n"); return;
    }
}

bool is_uppercase(char x)
{
    if (x > 64 && x < 91) return true; 
    else return false;
}

/*
 * Sort StringArray in alphabetical order, or if
 * non alpha characters are present sort by ASCII value
 *
 */

void str_array_merge(char** arr_data, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;

    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    char** left_arr = (char **)malloc(sizeof(n1) * sizeof(char*));
    char** right_arr = (char **)malloc(sizeof(n2) * sizeof(char*));

    for (i = 0; i < n1; ++i) 
    {
        left_arr[i] = arr_data[left + i];
    }
    for (j = 0; j < n2; ++j)
    {
        right_arr[j] = arr_data[mid + 1 + j];
    }

    i = j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        // First character from each char array
        char char_left = left_arr[i][0];
        char char_right = right_arr[j][0]; 

        // Is the current character alpha, sort alphabetically
        if (isalpha(char_left) && isalpha(char_right))
        {
            if (tolower(char_left) < tolower(char_right))
            {
                arr_data[k] = left_arr[i];
                ++i;
            }
            else
            {
                arr_data[k] = right_arr[j];
                ++j;
            }
        }
        else 
        {
            if (char_left < char_right)
            {
                arr_data[k] = left_arr[i];
                ++i;
            }
            else
            {
                arr_data[k] = right_arr[j];
                ++j;
            }
        }
        ++k;
    }

    while (i < n1)
    {
        arr_data[k] = left_arr[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr_data[k] = right_arr[j];
        ++j;
        ++k;
    }

    free(left_arr);
    free(right_arr);
}

void str_array_merge_sort(char** arr_data, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        str_array_merge_sort(arr_data, left, mid);
        str_array_merge_sort(arr_data, mid + 1, right);
        str_array_merge(arr_data, left, mid, right);
    }
}

void str_array_sort(StringArray *arr)
{
    size_t n = arr->size;
    if (n <= 1)
    {
        printf("Array must have more than one item to sort!\n");
        exit(1);
    }
    str_array_merge_sort(arr->data, 0, n - 1); 
}

void str_array_print(StringArray *arr)
{
    int i;
    printf("\n");
    printf("Array size    : %lu\n", arr->size);
    printf("Array capacity: %lu\n", arr->capacity);
    printf("[");
    for ( i = 0; i < arr->size; ++i )
    {
        if ( i == arr->size - 1 )
        {
            printf("%s", arr->data[i]);
        }
        else
        {
            printf("%s, ", arr->data[i]);
        }
    }
    printf("]");
    printf("\n\n");
}

void str_array_free(StringArray *arr)
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
// TODO Implement complementary function to return a StringArray based on index

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
