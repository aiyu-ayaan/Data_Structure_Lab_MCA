#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];

int top = -1;

void push(int data) // push element into stack
{
    if (top == MAX - 1) // if stack is full
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop() // pop element from stack
{
    if (top == -1) // if stack is empty
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int data = stack[top]; // get the element
        top--;                 // decrement top
        return data;           // return the element
    }
}

void main()
{
    int arr[MAX];
    int i;
    printf("Enter %d elements: ", MAX); // array input
    for (i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < MAX; i++)
        push(arr[i]); // push all elements into stack

    printf("Before Reverse\n");
    for (i = 0; i < MAX; i++)
        printf("%d\t", arr[i]);

    i = 0;
    while (top != -1)   // until stack is empty
    {                   // underflow
        arr[i] = pop(); // pop element from stack
        i++;
    }
    printf("\nAfter Reverse\n");

    for (i = 0; i < MAX; i++)
        printf("%d\t", arr[i]);
}