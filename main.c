#include <stdio.h>
#include <stdlib.h>
#include "include/dynamic_array.h"
#include "include/vector.h"

int main()
{
    DataTypes dtype = STRING;
    Vector* vec = vector(dtype);
    free(vec->data);
    free(vec);
    return 0;
}
