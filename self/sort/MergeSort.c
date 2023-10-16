#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + (r - l)) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void main()
{
    int arr[] = {12, 3, 56, 121, 67, 121, 3434};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("\n");
    printArr(arr, size);
}