#include <stdio.h>

#define VEC_TYPE int
#define VEC_PREFIX int_vector
#include "vector.h"

void vector_test(int size, int_vector_t *vec)
{
  int elem = 2;
  for ( int i = 0; i < size; ++i )
  {
    int_vector_push(vec, elem);
    elem *= 2;
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
  vector_test(20, &vec);
  pretty_print_vec(&vec);
  int_vector_pop(&vec);
  pretty_print_vec(&vec);
  return 0;
}
