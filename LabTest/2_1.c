/**
 * @author aiyu
 * @brief Stack using Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} typedef Node;

Node *top = NULL;

Node *createNode(int ele)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = ele;
    temp->next = NULL;
}

int under_flow(){
    return top == NULL;
}

int size()
{
    Node *trav = top;
    int size = 0;
    while (trav != NULL)
        trav = trav->next;

    return size;
}

void push(int ele)
{
    Node * temp =createNode(ele);
    if (top == NULL)
    {
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

int pop(){
    if(under_flow()){
        return -1;
    }
    if(size() ==1){
        int ele = top->data;
        free(top);
        top = NULL;
        return ele;
    }
    Node * yet_del = top;
    top = yet_del->next;
    int ele = yet_del->data;
    free(yet_del);
    return ele;
}

int peek()
{
    if (under_flow())
    {
        return -1;
    }
    return top->data;
}

void main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
}