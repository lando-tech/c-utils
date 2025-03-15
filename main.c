#include <stdio.h>
#include <stdlib.h>
#include "include/dynamic_array.h"

int main()
{
    StringArray *arr = create_array(10);
    append(arr, "Hello");
    append(arr, "World");
    print_array(arr);
    free_array(arr);
    return 0;
}
