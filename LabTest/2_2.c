/**
 * @author aiyu
 * @brief Queue using Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} typedef Node;

Node *front = NULL;
Node *rear = NULL;

Node *createNode(int ele)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = ele;
    temp->next = NULL;
}

int under_flow()
{
    return front == NULL;
}

int size()
{
    Node *trav = front;
    int size = 0;
    while (trav != NULL)
        trav = trav->next;

    return size;
}

void enqueue(int ele)
{
    Node *temp = createNode(ele);
    if (front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue()
{
    if (under_flow())
    {
        return -1;
    }
    if (size() == 1)
    {
        int ele = front->data;
        free(front);
        front = NULL;
        rear = NULL;
        return ele;
    }
    Node *yet_del = front;
    int ele = front->data;
    front = front->next;
    free(yet_del);
    return ele;
}

int peek()
{
    if (under_flow())
    {
        return -1;
    }
    return front->data;
}

void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    
}
