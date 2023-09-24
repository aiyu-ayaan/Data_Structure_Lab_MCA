#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

int is_underflow();
int is_overflow();
void enqueue(int);
int dequeue();
void display();


void main()
{
    int choice, ele;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the ele: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                ele = dequeue();
                if(ele != -1)
                    printf("The dequeued ele is %d\n", ele);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
int is_underflow()
{
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

int is_overflow()
{
    if ((rear + 1) % MAX == front && front != -1)
        return 1;
    return 0;
}

void enqueue(int ele)
{
    if (is_overflow())
        printf("Queue is full\n");
    else if (is_underflow())
    {
        front = rear = 0;
        queue[rear] = ele;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = ele;
    }
}

int dequeue()
{
    int ele;
    if (is_underflow())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (front == rear)
    {
        ele = queue[front];
        front = rear = -1;
    }
    else
    {
        ele = queue[front];
        front = (front + 1) % MAX;
    }
    return ele;
}
void display()
{
    int i;
    if (is_underflow())
        printf("Queue is empty\n");
    else
    {
        printf("The elements in the queue are: ");
        for (i = front; i != rear; i = (i + 1) % MAX)
            printf("%d ", queue[i]);
        printf("%d\n", queue[i]);
    }
}