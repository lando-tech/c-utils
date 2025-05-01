#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef VEC_TYPE
#error "You must define a VEC_TYPE before including vector.h"
#endif

#ifndef VEC_PREFIX
#error "You must define a VEC_PREFIX before including vector.h"
#endif

#define CAT2(a, b) a##b
#define FUNC(name) CAT2(VEC_PREFIX, name)

typedef struct
{
    VEC_TYPE *data;
    size_t size;
    size_t capacity;
} FUNC(_t);

static inline void FUNC(_init)(FUNC(_t) *vec)
{
    vec->capacity = 10;
    vec->data = malloc(sizeof(VEC_TYPE) * vec->capacity);
    vec->size = 0;
}

#endif
