
/**
 * @author aiyu
 * @brief Stack using Array (Static Stack)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], top = -1;

int under_flow()
{
    return top == -1;
}

int over_flow()
{
    return top == MAX-1;
}

void push(int ele)
{
    if (over_flow())
    {
        printf("\nStack is full");
        return;
    }
    stack[++top] = ele;
    printf("\nElement add !!");
}

int pop()
{
    if (over_flow())
    {
        printf("\nStack is empty");
        return -1;
    }
    int ele = stack[top--];
    return ele;
}

int peek()
{
    if (over_flow())
    {
        printf("\nStack is empty");
        return -1;
    }
    return stack[top];
}

void display()
{
    if (over_flow())
    {
        printf("\nStack is empty");
        return;
    }
    printf("\n");
    for (int i = 0; i <= top; i++)
        printf("%d \t", stack[i]);
}

void main()
{
    push(12);
    push(13);
    push(14);
    printf("\nPeek :- %d", peek());
    printf("\nPop :- %d",pop());

    display();
}