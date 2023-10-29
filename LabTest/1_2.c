
/**
 * @author aiyu
 * @brief Queue using Array (Static Queue)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

int under_flow()
{
    return front == -1 || front > rear;
}

int over_flow()
{
    return rear == MAX - 1;
}

void inqueue(int ele)
{
    if (over_flow())
    {
        printf("\nQueue is Full !!");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ele;
}

int dequeue()
{
    if (under_flow())
    {
        return -1;
    }
    int ele = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        ++front;
    return ele;
}

void display()
{
    if(under_flow()){
        printf("\nQueue is empty!!");
        return;
    }
    printf("\n");
    for (int i = front; i <= rear; i++)
        printf("%d \t ", queue[i]);
}

void main()
{
    inqueue(1);
    inqueue(2);
    inqueue(3);
    inqueue(4);
    inqueue(5);
    printf("Item remove %d\n", dequeue()); 
    inqueue(6); // Limitation of Linear queue 
    display();
    printf("\n\n%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    display();
}