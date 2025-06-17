#include <stdio.h>
#include <stdlib.h>
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

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *left_arr = (int *)malloc(sizeof(n1 * sizeof(int)));
    int *right_arr = (int *)malloc(sizeof(n2 * sizeof(int)));

    for (i = 0; i < n1; ++i)
    {
        left_arr[i] = arr[left + i];
    }
    for (j = 0; j < n2; ++j)
    {
        right_arr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            ++i;
        }
        else
        {
            arr[k] = right_arr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = left_arr[i];
        ++k;
        ++i;
    }
    while (j < n2)
    {
        arr[k] = right_arr[j];
        ++k;
        ++j;
    }
    free(left_arr);
    free(right_arr);
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort_test()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
	
    merge_sort(arr, 0, n - 1);
    
    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

