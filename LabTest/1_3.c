
/**
 * @author aiyu
 * @brief Circular Queue using Array (Static Circular Queue)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

int under_flow()
{
    return front == -1 && rear == -1;
}

int over_flow()
{
    return (rear + 1) % MAX == front && front != -1;
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
    rear = (rear + 1) % MAX;
    queue[rear] = ele;
    printf("\nElement added %d\n", ele);
}

int dequeue()
{
    if (under_flow())
        return -1;
    int ele = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return ele;
}
void display()
{
    if (under_flow())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements in the queue are: ");
    int i = front;
    do
    {
        printf("%d ",~ queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}
void main()
{
    inqueue(1);
    inqueue(2);
    inqueue(3);
    inqueue(4);
    inqueue(5);
    printf("Item remove %d\n", dequeue());
    inqueue(6);
    display();
    printf("\n\n%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    display();
}