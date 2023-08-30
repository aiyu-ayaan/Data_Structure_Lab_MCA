/*
    Linked List program
    @author: aiyu
    @since : 30-08-2023
*/
#include <stdio.h>
#include <stdlib.h>

// Defines all my macros
#define print(f) printf(f)
#define print_int(f) printf("%d\t", f)
#define scan_int(f) scanf("%d", &f)

//  Node
struct Node
{
    int data;
    struct Node *next;
} typedef Node;

// Head
Node *ROOT = NULL;

// Function prototypes
int is_underflow();
Node *create_node(int);
Node *trav_to_last_node();
void insert_node(int);
void display();

void main()
{
    int choise;
    while (1)
    {
        print("\n\nLinked List Program.\n1.Insert_node\n2.Display\n5.Exit\n\nEnter your choise :- ");
        scan_int(choise);
        switch (choise)
        {
        case 1:
        {
            int ele;
            print("Enter value :- ");
            scan_int(ele);
            insert_node(ele);
        }
        break;
        case 2:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            print("Enter valid choise !!!!");
        }
    }
}

// Function to check if the linked list is underflow
int is_underflow()
{
    if (ROOT == NULL)
        return 1; // Linked list is empty (underflow)
    return 0;     // Linked list is not empty
}

// Function to create a new node with given data
Node *create_node(int ele)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = ele;
    temp->next = NULL;
    return temp;
}

// Function to traverse to the last node in the linked list
Node *trav_to_last_node()
{
    Node *trav = ROOT;
    while (trav->next != NULL)
        trav = trav->next;
    return trav;
}

// Function to insert a new node with given data at the end of the linked list
void insert_node(int ele)
{
    Node *temp = create_node(ele);
    if (is_underflow())
    {
        ROOT = temp;
        return;
    }
    Node *trav = trav_to_last_node();
    trav->next = temp;
}

// Function to display the data in all nodes of the linked list
void display()
{
    Node *trav = ROOT;
    while (trav != NULL)
    {
        print_int(trav->data);
        trav = trav->next;
    }
}
