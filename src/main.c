#include <stdio.h>
#include <stdbool.h>
#include "string_utils.h"
#include "algorithms.h"

#define VEC_TYPE int
#define VEC_PREFIX int_vector
#include "data_types.h"
#include "vector.h"

void print_int_vec(int_vector_t* vec)
{
    printf("\n");
    printf("Vector Size    : %lu\n", vec->size);
    printf("Vector Capacity: %lu\n", vec->capacity);
    printf("[");

    for (int i = 0; i < vec->size; ++i)
    {
        if ( i == vec->size - 1 )
        {
            printf("%d", vec->data[i]);
        }
        else
        {
            printf("%d, ", vec->data[i]);
        }
    }
    printf("]\n");
}

// void stress_test_str_array()
// {
//     StringArray *arr = str_array_init(10);
//     char* test = "test";
//     for (int i = 0; i < 10000; ++i)
//     {
//         str_array_append(arr, test);
//     }
//     str_array_print(arr);
//     str_array_free(arr);
// }

void test_str_array()
{
    StringArray *string_arr = str_array_init(10);
    str_array_append(string_arr, "hello");
    str_array_append(string_arr, "world");
    str_array_append(string_arr, "people");

    str_array_print(string_arr);
    str_array_pop(string_arr);
    str_array_print(string_arr);
    
    str_array_free(string_arr);
}

void test_str_array_sort()
{
    StringArray *arr = str_array_init(10);

    str_array_append(arr, "mike");
    str_array_append(arr, "Bravo");
    str_array_append(arr, "zulu");
    str_array_append(arr, "alpha");
    str_array_append(arr, "Echo");
    str_array_append(arr, "$3,122");
    str_array_append(arr, "lima");
    str_array_append(arr, "charlie");
    str_array_append(arr, "eddie");
    str_array_append(arr, "test");
    str_array_append(arr, "alpine");

    printf("Array before sort:\n");
    str_array_print(arr);

    str_array_sort(arr);

    printf("Array after sort:\n");
    str_array_print(arr);

    str_array_free(arr);
}

void test_vector()
{
    int_vector_t int_vec;
    int_vector_init(&int_vec);
    int_vector_push(&int_vec, 10);
    int_vector_push(&int_vec, 5);
    int_vector_push(&int_vec, 1);

    print_int_vec(&int_vec);
    int_vector_pop(&int_vec);
    print_int_vec(&int_vec);

    int_vector_free(&int_vec);
}

int main()
{
    test_str_array_sort();
    test_vector();
    return 0;
}
