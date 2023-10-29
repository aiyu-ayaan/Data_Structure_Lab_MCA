/**
 * @author aiyu
 * @brief Program to reverse the linked list.
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

void reverse()
{
    Node *prev = NULL;
    Node *curr = ROOT;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    ROOT = prev;
}

void display()
{
    Node *temp = ROOT;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    display();

    reverse();

    display();

}