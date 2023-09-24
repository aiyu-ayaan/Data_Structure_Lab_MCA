#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} typedef Node;

Node *ROOT = NULL;

/**
 * @brief Insert a node at the beginning of the linked list
 */
void insert_at_beginning(int ele)
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
        new_node->next = ROOT;
        ROOT = new_node;
    }
}

/**
 * @brief Insert a node at the end of the linked list
 */

void insert_at_end(int ele)
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

/**
 * @brief Insert a node at the middle of the linked list
 */

void insert_at_middle(int ele, int pos)
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
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

/**
 * @brief Delete a node at the beginning of the linked list
 */
void delete_at_beginning()
{
    if (ROOT == NULL) // if list is empty
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = ROOT;
        ROOT = ROOT->next;
        free(temp);
    }
}

/**
 * @brief Delete a node at the end of the linked list
 */

void delete_at_end()
{
    if (ROOT == NULL) // if list is empty
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = ROOT;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

/**
 * @brief Delete a node at the middle of the linked list
 */
void delete_at_middle(int pos)
{
    if (ROOT == NULL) // if list is empty
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp = ROOT;
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

void display()
{
    Node *temp = ROOT;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/**
 * @brief Display the linked list
 */
void main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_beginning(40);
    insert_at_beginning(50);
    insert_at_middle(60, 3);

    // delete
    delete_at_beginning();
    delete_at_end();
    delete_at_middle(3);
    display();
}