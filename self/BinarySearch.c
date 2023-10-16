#include <stdio.h>
#include <stdlib.h>

int binarySearchItterative(int[], int, int, int);

int binarySearchRecursive(int[], int, int, int);

void main()
{
    int arr[] = {4, 5, 9, 10, 14, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearchRecursive(arr, 0, size-1, 14);


    printf("%d", (index != -1 ? index + 1 : -1));
}

int binarySearchItterative(int arr[], int start, int end, int ele)
{
    while (end <= start)
    {
        int m = start + end / 2;

        if (arr[m] == ele)
            return m;
        if (arr[m] < ele)
            start = m + 1;
        else
            end = m - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int start, int end, int ele)
{

    if(end >= start){
        int m = (start + end) / 2;

        if (arr[m] == ele)
            return m;

        if (arr[m] < ele)
            return binarySearchRecursive(arr, m + 1, end, ele); 
        else
            return binarySearchRecursive(arr, start, m - 1, ele);
    }
    return -1;
}