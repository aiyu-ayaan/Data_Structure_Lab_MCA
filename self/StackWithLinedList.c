#include <stdio.h>
#include <stdlib.h>

#define _menu_message printf("\n\nPress 1 to push.\nPress 2 to pop\nPress 3 to peek.\nPress 4 display.\\\nPress 5 to get size\nPress 6 to exit.\nEnter your choice:- ")
#define _insert_message printf("\nItem is Inserted !!")
#define _under_flow_message printf("\nStack is empty")

#define print_int(m) printf("%d", m)
#define scan_int(m) scanf("%d", &m)

struct Stack
{
    int data;
    struct Stack *next;
} typedef Stack;

Stack *top = NULL;

Stack *createNode(int);
int is_underflow();
void push(int);
int pop();
int peek();
void display();
int size();

void main()
{
    printf("--------------------Stack using Linked List--------------------");
    int choice;
    while (1)
    {
        _menu_message;
        scan_int(choice);
        switch (choice)
        {
        case 1:
        {
            int ele;
            printf("\nEnter Element :- ");
            scan_int(ele);
            push(ele);
        }
        break;
        case 2:
            printf("\nElement is poped %d !!!", pop());
            break;
        case 3:
            printf("\nTop most element is %d ", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nSize of stack is %d", size());
            break;
        case 6:
            exit(0);
        default:
            printf("\nEnter valid option !!!!");
        }
    }
}

int is_underflow()
{
    if (top == NULL)
        return 1;
    return 0;
}

Stack *createNode(int ele)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = ele;
    node->next = NULL;
    return node;
}

int size()
{
    Stack *trav = top;
    int size = 0;
    while (trav != NULL)
        trav = trav->next;

    return size;
}

void push(int ele)
{
    Stack *node = createNode(ele);
    if (is_underflow())
    {
        top = node;
        _insert_message;
        return;
    }
    node->next = top;
    top = node;
}

int pop()
{
    if (is_underflow())
    {
        _under_flow_message;
        return -1;
    }
    if (size() == 1)
    {
        int ele = top->data;
        free(top);
        top = NULL;
        return ele;
    }
    Stack *yet_del = top;
    top = yet_del->next;
    int ele = yet_del->data;
    free(yet_del);
    return ele;
}

int peek()
{
    if (is_underflow())
    {
        _under_flow_message;
        return -1;
    }
    return top->data;
}

void display()
{
    if (is_underflow())
    {
        _under_flow_message;
        return;
    }
    Stack *trav = top;
    while (trav != NULL)
    {
        printf("\t %d", trav->data);
        trav = trav->next;
    }
}