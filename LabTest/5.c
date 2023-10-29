/**
 * @author aiyu
 * @brief Program to count the number of nodes in the linear linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} typedef Node;

Node *ROOT = NULL;

void createNode(int ele)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = ele;
    new_node->next = NULL;
    if (ROOT == NULL) // if list is empty
    {
        ROOT = new_node;
    }
    else
    {
        Node *temp = ROOT;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int count()
{
    Node *temp = ROOT;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    printf("Number of nodes in the linked list: %d\n", count());
}