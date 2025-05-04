#include <stddef.h>
#include <stdio.h>

#define VEC_TYPE int
#define VEC_PREFIX int_vector
#include "vector.h"

void vector_test(int size, int_vector_t *vec)
{
  int elem = 1;
  for ( int i = 0; i < size; ++i )
  {
    int_vector_push(vec, elem);
    // printf("Element %d added to vector\n", elem);
    elem++;
  }
}

void pretty_print_vec(int_vector_t *vec)
{
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
  int_vector_t vec;
  int_vector_init(&vec);
  vector_test(10, &vec);
  // size_t index = 3;
  // printf("Data at index: %d = %d\n", 3, int_vector_get(&vec, index));
  int_vector_pop(&vec);
  int_vector_free(&vec);
  return 0;
}
