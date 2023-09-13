#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void stackPart();
void queuePart();

// -------------------------- Stack --------------------------

int stack[MAX];
int top = -1;

void push(int);
int pop();
int peekStack();
void displayStack();
void statusStack();

// ----------------------- Queue -----------------------------

int queue[MAX];

int front = -1, rear = -1;
void insert(int);
int delete();
int peekQueue();
void displayQueue();
void statusQueue();

// ----------------------- Main ------------------------------
void main()
{
    int type_choice, val;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Stack\n2. Queue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &type_choice);

        switch (type_choice)
        {
        case 1:
            stackPart();
            break;

        case 2:
            queuePart();
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong selection!!! Try again!!!\n");
        }
    }
}

void stackPart()
{
    int choice, val;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Status\n6. Exit\n");
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
            val = peekStack();
            if (val != -1)
                printf("The top element is %d\n", val);
            break;

        case 4:
            displayStack();
            break;
        case 5:
            statusStack();
            break;
        case 6:
            exit(0);

        default:
            printf("Wrong selection!!! Try again!!!\n");
        }
    }
}

void queuePart()
{
    int choice, val;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Status \n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &val);
            insert(val);
            break;

        case 2:
            val = delete ();
            if (val != -1)
                printf("The deleted element is %d\n", val);
            break;

        case 3:
            val = peekQueue();
            if (val != -1)
                printf("The front element is %d\n", val);
            break;

        case 4:
            displayQueue();
            break;

        case 5:
            statusQueue();
            break;
        case 6:
            exit(0);

        default:
            printf("Wrong selection!!! Try again!!!\n");
        }
    }
}

// ----------------------- Stack -----------------------------

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

int peekStack()
{
    if (top == -1)
    {
        printf("Stack is empty!!!\n");
        return -1;
    }
    else
        return stack[top];
}

void displayStack()
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

void statusStack()
{
    printf("Stack is having %d space and %d empty space !!", (top + 1), (MAX - (top + 1)));
}

//  ----------------------- Queue -----------------------------

void insert(int val)
{
    if (rear == MAX - 1)
        printf("Queue is full!!! Insertion is not possible!!!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
    }
}

int delete()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!!! Deletion is not possible!!!\n");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

int peekQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!!!\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void displayQueue()
{
    int i;
    if (front == -1 || front > rear)
        printf("Queue is empty!!!\n");
    else
    {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

void statusQueue()
{
    printf("Queue is having %d space element and %d empty space !!", (rear + 1), (MAX - (rear + 1)));
}
