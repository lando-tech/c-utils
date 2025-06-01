#include <stdio.h>
#include "algorithms.h"

/*
 * Simple implementation of bubble sort
 */
void bubble_sort(int arr[], int size)
{
    int temp;
    for ( int i = 0; i < size; ++i )
    {
        for ( int j = 0; j < size - i - 1; ++j )
        {
            if ( arr[j] > arr[j + 1] )
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 * Merge sort
 */
