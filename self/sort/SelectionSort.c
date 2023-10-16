#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    int j, min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(&arr[min], &arr[i]);
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
    selectionSort(arr, size);
    printf("\n");
    printArr(arr, size);
}