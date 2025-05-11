#include <stdio.h>
#include "string_utils.h"

#define VEC_TYPE int
#define VEC_PREFIX int_vector
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

int main()
{
    StringArray *string_arr = create_array(10);
    append(string_arr, "hello");
    append(string_arr, "world");
    append(string_arr, "people");
    print_array(string_arr);

    pop(string_arr);
    print_array(string_arr);

    int_vector_t int_vec;
    int_vector_init(&int_vec);
    int_vector_push(&int_vec, 10);
    int_vector_push(&int_vec, 5);
    int_vector_push(&int_vec, 1);
    print_int_vec(&int_vec);    

    int_vector_pop(&int_vec);
    print_int_vec(&int_vec);

    int_vector_free(&int_vec);
    free_array(string_arr);
    return 0;
}
