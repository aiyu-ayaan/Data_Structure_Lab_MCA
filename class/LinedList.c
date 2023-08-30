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

#define _Node Node * // Define macro for Node *

// Head
_Node ROOT = NULL;

// Function prototypes
int is_underflow();
_Node create_node(int);
_Node trav_to_last_node();
int size();
void insert_node();
void insert_at_end(int);
void insert_at_first(int);
int insert_at_position(int, int);
void display();

void main()
{
    int choise;
    while (1)
    {
        print("\n\nLinked List Program.\n1.Insert_node\n2.Display\n3.Check Size\n5.Exit\n\nEnter your choise :- ");
        scan_int(choise);
        switch (choise)
        {
        case 1:
            insert_node();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Size of Linked List is %d", size());
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
_Node create_node(int ele)
{
    _Node temp = (_Node)malloc(sizeof(Node));
    temp->data = ele;
    temp->next = NULL;
    return temp;
}

// Function to traverse to the last node in the linked list
_Node trav_to_last_node()
{
    _Node trav = ROOT;
    while (trav->next != NULL)
        trav = trav->next;
    return trav;
}

int size()
{
    if (is_underflow())
        return 0;

    int size = 0;
    _Node trav = ROOT;
    while (trav != NULL)
    {
        size++;
        trav = trav->next;
    }
    return size;
}

void insert_node()
{

    int choise, ele, is_added = 1;
    print("\nEnter value :- ");
    scan_int(ele);
    while (is_added)
    {
        print("\n1. At last\n2. At middle\n3. At First\nEnter your choise :- ");
        scan_int(choise);
        switch (choise)
        {
        case 1:
        {
            insert_at_end(ele);
            is_added = 0;
            continue;
        }
        case 2:
        {
            int pos;
            print("\nEnter Position :- ");
            scan_int(pos);
            if (pos > size()) // if enter position is greater then the actual size of list
            {
                print("\nEnter valid position !!!");
                continue;
            }
            int is_pos_avilable = insert_at_position(ele, pos);
            if (is_pos_avilable == 0) // check for position 0
            {
                print("\nPosition must me greater than 0..");
                continue;
            }

            is_added = 0;
            continue;
        }
        case 3:
        {
            insert_at_first(ele);
            is_added = 0;
            continue;
        }
        default:
            print("Enter valid Choise.\n");
        }
    }
}

// Function to insert a new node with given data at the end of the linked list
void insert_at_end(int ele)
{
    _Node temp = create_node(ele);
    if (is_underflow())
    {
        ROOT = temp;
        return;
    }
    _Node trav = trav_to_last_node();
    trav->next = temp;
}

// Function to insert a new node with given data at the any avilable position of the linked list
int insert_at_position(int ele, int pos)
{
    if (pos == 0)
        return 0;

    if (pos == 1)
    {
        insert_at_first(ele);
        return 1;
    }
    _Node temp = create_node(ele);
    _Node trav = ROOT;
    int i = 1;
    while (i < pos - 1)
    {
        trav = trav->next;
    }
    temp->next = trav->next;
    trav->next = temp;
    return 1;
}

// Function to insert a new node with given data at the first position of the linked list
void insert_at_first(int ele)
{
    _Node temp = create_node(ele);
    temp->next = ROOT;
    ROOT = temp;
}

// Function to display the data in all nodes of the linked list
void display()
{
    _Node trav = ROOT;
    while (trav != NULL)
    {
        print_int(trav->data);
        trav = trav->next;
    }
}
