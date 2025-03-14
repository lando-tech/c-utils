#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

int main()
{
    StringArray *arr = create_array(5);
    append(arr, "hello");
    print_array(arr);
    free_array(arr);
    return 0;
}
