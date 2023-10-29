/**
 * @author aiyu
 * @brief Program to create, add, remove, display elements from the doubly linked list
 */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

Node *HEAD = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert_at_beginning(int ele)
{
    Node *new_node = createNode(ele);
    if (HEAD == NULL)
    {
        HEAD = new_node;
    }
    else
    {
        new_node->next = HEAD;
        HEAD->prev = new_node;
        HEAD = new_node;
    }
}

void insert_at_end(int ele)
{
    Node *new_node = createNode(ele);
    if (HEAD == NULL)
    {
        HEAD = new_node;
    }
    else
    {
        Node *temp = HEAD;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void delete_at_beginning()
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = HEAD;
        HEAD = HEAD->next;
        if (HEAD != NULL)
        {
            HEAD->prev = NULL;
        }
        free(temp);
    }
}

void delete_at_end()
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = HEAD;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            HEAD = NULL;
        }
        free(temp);
    }
}

void display()
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_beginning(40);
    insert_at_beginning(50);

    delete_at_beginning();
    delete_at_end();
    display();

    return 0;
}