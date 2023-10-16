#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
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
    bubbleSort(arr, size);
    printf("\n");
    printArr(arr, size);
}