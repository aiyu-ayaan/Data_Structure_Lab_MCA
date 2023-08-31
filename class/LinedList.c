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
#define _valid_message printf("\nEnter valid choice !!!!")
#define _valid_pos_message printf("\nEnter valid Position !!!!")
#define _c_d_message printf("\n1.At last\n2.At middle\n3.At First\nEnter your choice :- ")
#define _added_message printf("\nNode is Added!!!")
#define _deleted_message printf("\nNode is Deleted !!")
#define _position_err_message printf("\nPosition must me greater than 0..")
#define _bye_message printf("\nGood Bye ~_~")

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
void delete_node();
void delete_the_last_element();
void delete_at_end();
void delete_at_first();
int delete_at_position(int);

void main()
{
    int choice;
    print("\n\n--------------------------Linked List Program.--------------------------");
    while (1)
    {
        print("\n1.Insert Node\n2.Display\n3.Check Size\n4.Delete Node\n5.Exit\n\nEnter your choice :- ");
        scan_int(choice);
        switch (choice)
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
        case 4:
            delete_node();
            break;
        case 5:
        {
            _bye_message;
            exit(0);
        }
        break;
        default:
            _valid_message;
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

    int choice, ele, is_added = 1;
    print("\nEnter value :- ");
    scan_int(ele);
    while (is_added)
    {
        _c_d_message;
        scan_int(choice);
        switch (choice)
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
                _valid_pos_message;
                continue;
            }
            int is_pos_avilable = insert_at_position(ele, pos);
            if (is_pos_avilable == 0) // check for position 0
            {
                _position_err_message;
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
            _valid_message;
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
    _added_message;
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
    while (i++ < pos - 1)
        trav = trav->next;

    temp->next = trav->next;
    trav->next = temp;
    _added_message;
    return 1;
}

// Function to insert a new node with given data at the first position of the linked list
void insert_at_first(int ele)
{
    _Node temp = create_node(ele);
    temp->next = ROOT;
    ROOT = temp;
    _added_message;
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

void delete_node()
{
    if (is_underflow())
    {
        print("\nLinked list is empty !!.");
        return;
    }
    int choice, is_deleted = 1;
    while (is_deleted)
    {
        _c_d_message;
        scan_int(choice);
        switch (choice)
        {
        case 1:
        {
            delete_at_end();
            is_deleted = 0;
            continue;
        }
        case 2:
        {
            int pos;
            print("\nEnter Position :- ");
            scan_int(pos);
            if (pos > size()) // if enter position is greater then the actual size of list
            {
                _valid_pos_message;
                continue;
            }
            int is_pos_avilable = delete_at_position(pos);
            if (is_pos_avilable == 0) // check for position 0
            {
                _position_err_message;
                continue;
            }

            is_deleted = 0;
            continue;
        }
        case 3:
        {
            delete_at_first();
            is_deleted = 0;
            continue;
        }

        default:
            _valid_message;
        }
    }
}

void delete_at_end()
{
    // their is only 1 node
    if (size() == 1)
    {
        delete_the_last_element();
        return;
    }

    // traverse to send last node
    _Node trav = ROOT;
    while (trav->next->next != NULL)
        trav = trav->next;

    // Now trav is pointing to send last node
    _Node last_node = trav->next;
    trav->next = NULL;
    free(last_node);
    _deleted_message;
}

void delete_the_last_element()
{
    _Node last_item = ROOT;
    ROOT = NULL;
    free(last_item);
}

void delete_at_first()
{
    if (size() == 1)
    {
        delete_the_last_element();
        return;
    }
    _Node yet_first = ROOT;
    ROOT = yet_first->next;
    free(yet_first);
    _deleted_message;
}

int delete_at_position(int pos)
{
    if (pos == 0)
        return 0;
    if (pos == 1)
    {
        delete_at_first();
        return 1;
    }
    if (pos == size())
    {
        delete_at_end();
        return 1;
    }
    int i = 1;
    _Node trav = ROOT;
    while (i++ < pos - 1)

        trav = trav->next;

    _Node delete_node = trav->next;
    trav->next = delete_node->next;
    free(delete_node);
    _deleted_message;
    return 1;
}