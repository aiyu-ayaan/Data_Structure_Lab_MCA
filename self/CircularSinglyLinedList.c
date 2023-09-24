/*
    Circular Linked List program
    @author: aiyu
    @since : 04-09-2023
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
#define _empty_list_message printf("\nLinked list is empty !!.")
#define _added_message printf("\nNode is Added!!!")
#define _deleted_message printf("\nNode is Deleted !!")
#define _position_err_message printf("\nPosition must me greater than 0..")
#define _element_not_found print("\nEntered element not found !!")
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
int search_value(int);
void delete_by_value(int);

void main()
{
    int choice;
    print("\n\n--------------------------Linked List Program.--------------------------");
    while (1)
    {
        print("\n\n1.Insert Node\n2.Display\n3.Check Size\n4.Delete Node\n5.Delete By Value\n6.Search Item\n7.Exit\n\nEnter your choice :- ");
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
            int ele;
            print("Enter value you want to delete :- ");
            scan_int(ele);
            delete_by_value(ele);
        }
        break;
        case 6:
        {
            int ele;
            print("Enter value you want to search :- ");
            scan_int(ele);
            int pos = search_value(ele);
            if (pos == -1)
                _element_not_found;
            else
                printf("\nEntered element is at %d position", (pos + 1));
        }
        break;
        case 7:
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
    while (trav->next != ROOT)
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
        temp->next = ROOT;
        return;
    }
    _Node trav = trav_to_last_node();
    trav->next = temp;
    temp->next = ROOT;
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
    _Node trav = trav_to_last_node();
    trav->next = ROOT;
    _added_message;
}

// Function to display the data in all nodes of the linked list
void display()
{
    if (is_underflow())
    {
        _empty_list_message;
        return;
    }
    _Node trav = ROOT;
    while (trav != ROOT)
    {
        print_int(trav->data);
        trav = trav->next;
    }
}

// Function to delete a node from the linked list based on user's choice
void delete_node()
{
    if (is_underflow())
    {
        _empty_list_message;
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

            if (pos > size()) // if entered position is greater than the actual size of the list
            {
                _valid_pos_message;
                continue;
            }

            int is_pos_available = delete_at_position(pos);

            if (is_pos_available == 0) // check for position 0
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

// Function to delete the last node from the linked list
void delete_at_end()
{
    // If there's only 1 node
    if (size() == 1)
    {
        delete_the_last_element();
        return;
    }

    // Traverse to find the second last node
    _Node trav = ROOT;
    while (trav->next->next != ROOT)
        trav = trav->next;

    // Now trav is pointing to the second last node
    _Node last_node = trav->next;
    trav->next = NULL;
    free(last_node);
    _deleted_message;
}

// Function to delete the last element when there's only 1 node
void delete_the_last_element()
{
    _Node last_item = ROOT;
    ROOT = ROOT;
    free(last_item);
}

// Function to delete the first node from the linked list
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

// Function to delete a node from the linked list at a specified position
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

// Function to search for a value in the linked list and return its position
int search_value(int ele)
{
    _Node trav = ROOT;
    int pos = 0;

    while (trav != ROOT)
    {
        if (trav->data == ele)
            return pos;
        trav = trav->next;
        pos++;
    }

    return -1;
}

// Function to delete a node from the linked list based on a given value
void delete_by_value(int ele)
{
    int pos = search_value(ele);

    if (pos == -1)
    {
        _element_not_found;
        return;
    }

    delete_at_position((++pos)); // ++ because search_value return n-1 postion.
}
