#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}

void insertionSort(int arr[], int size)
{
    int j, key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i -1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
}

void main()
{
    int arr[] = {12, 3, 56, 121, 67, 121, 3434};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    insertionSort(arr, size);
    printf("\n");
    printArr(arr, size);
}