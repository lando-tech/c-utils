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

int main()
{
  int_vector_t vec;
  int_vector_init(&vec);
  vector_test(12, &vec);
  return 0;
}
