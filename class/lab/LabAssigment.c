#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define print(f) printf(f)
#define print_int(f) printf("%d\t", f)
#define print_char(f) printf("%s\t", f)
#define scan_int(f) scanf("%d", &f)
#define scan_char(f) scanf("%s", &f)
#define scan_float(f) scanf("%f", &f)
#define _valid_message printf("\nEnter valid choice !!!!")
#define _c_d_message printf("\n1.Create Student data\n2.Display all student data\n3.Count\n4.Sort (Roll No)\nEnter choice :- ")
#define _empty_list_message printf("\nStudent list is empty !!.")
#define _added_message printf("\nStudent data is Added!!!")

struct Student
{
    int roll_no;
    char name[20];
    int sem;
    float age;
    struct Student *next;
} typedef Student;

#define _Student Student * // Define macro for Student *

_Student ROOT = NULL;

int is_underflow();
void display();
_Student create_node(int, char[20], int, float);
_Student trav_to_last_node();
int display_size();
void insert_node();
void sort();

void main()
{
    int choice;
    print("\n\n--------------------------Student Data Program.--------------------------");
    while (1)
    {
        print("\n\n1.Insert Student data\n2.Display all student data\n3.Count\n4.Sort (Roll No)\n5.Exit\n\nEnter your choice :- ");
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
            printf("\nTotal Student data is %d", display_size());
            break;
        case 4:
            sort();
            break;
        case 5:
            print("\nGood Bye ~_~");
            exit(0);
        default:
            _valid_message;
            break;
        }
    }
}

int is_underflow()
{
    if (ROOT == NULL)
        return 1;

    return 0;
}

_Student create_node(int roll_no, char name[20], int sem, float age)
{
    _Student new_node = (_Student)malloc(sizeof(Student));
    new_node->roll_no = roll_no;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->sem = sem;
    new_node->next = NULL;
    return new_node;
}

_Student trav_to_last_node()
{
    _Student temp = ROOT;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void insert_node()
{
    int roll_no, sem;
    char name[20];
    float age;
    print("\nEnter Roll No :- ");
    scan_int(roll_no);
    print("\nEnter Name :- ");
    scanf("%s", name);
    print("\nEnter Sem :- ");
    scan_int(sem);
    print("\nEnter Age :- ");
    scan_float(age);
    _Student new_node = create_node(roll_no, name, sem, age);
    if (is_underflow())
    {
        ROOT = new_node;
        _added_message;
        return;
    }

    _Student last_node = trav_to_last_node();
    last_node->next = new_node;
    _added_message;
}

int display_size()
{
    int count = 0;
    _Student temp = ROOT;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display()
{
    if (is_underflow())
    {
        _empty_list_message;
        return;
    }
    _Student temp = ROOT;
    print("\n\nRoll No\t\tName\t\tSem\t\tAge\n");
    while (temp != NULL)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f", temp->roll_no, temp->name, temp->sem, temp->age);
        print("\n");
        temp = temp->next;
    }
}

void sort()
{
    if (is_underflow())
    {
        _empty_list_message;
        return;
    }
    _Student temp = ROOT;
    int size = display_size();
    int arr[size];
    int i = 0;
    while (temp != NULL)
    {
        arr[i] = temp->roll_no;
        i++;
        temp = temp->next;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    print("\n\nRoll No\t\tName\t\tSem\t\tAge\n");
    for (int i = 0; i < size; i++)
    {
        temp = ROOT;
        while (temp != NULL)
        {
            if (temp->roll_no == arr[i])
            {
                printf("%d\t\t%s\t\t%d\t\t%.2f", temp->roll_no, temp->name, temp->sem, temp->age);
                print("\n");
            }
            temp = temp->next;
        }
    }
}
