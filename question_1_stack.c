// stack using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int);
int pop();
int peek();
void display();

int main(int *args[], char *argv[])
{
    int choice, val;

    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            val = pop();
            if (val != -1)
                printf("The deleted element is %d\n", val);
            break;

        case 3:
            val = peek();
            if (val != -1)
                printf("The top element is %d\n", val);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong selection!!! Try again!!!\n");
        }
    }
    return 0;
}

void push(int val)
{
    if (top == MAX - 1)
        printf("Stack is full!!! Insertion is not possible!!!\n");
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack is empty!!! Deletion is not possible!!!\n");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty!!!\n");
        return -1;
    }
    else
        return stack[top];
}

void display()
{
    int i;
    if (top == -1)
        printf("Stack is empty!!!\n");
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
