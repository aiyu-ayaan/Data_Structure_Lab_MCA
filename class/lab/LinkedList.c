#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} typedef Node;

Node *ROOT = NULL;

int isEmpty();
void insertNode(int);
void displayNode();

void main()
{

    int choice;
    while (1)
    {
        printf("\n\nWelcome to Linked List.\n1. Insert\n2. Display\n5. Exit !!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int ele;
            printf("Enter your Element:- ");
            scanf("%d", &ele);
            insertNode(ele);
        }
        break;
        case 2:
            displayNode();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice !!!!\n");
        }
    }
}

void insertNode(int ele)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = ele;
    temp->link = NULL;
    if (isEmpty())
    {
        ROOT = temp;
        return;
    }
    Node *trv = ROOT;
    while (trv->link != NULL)
    {
        trv = trv->link;
    }
    trv->link = temp;
}

void displayNode()
{
    if (isEmpty())
    {
        printf("Linked List is empty !! ");
        return;
    }
    Node *trv = ROOT;
    while (trv != NULL)
    {
        printf("%d -> ", trv->data);
        trv = trv->link;
    }
}

int isEmpty()
{
    if (ROOT == NULL)
    {
        return 1;
    }
    return 0;
}
