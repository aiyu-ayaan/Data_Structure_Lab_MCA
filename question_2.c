
/**
 * @aurthor: Aiyu Ayaan
Develop and implement a menu driven program in C for the following Array operations

a. Creating Array of N Integer elements.

b. Display of Array elements with suitable headings.

c. Inserting an element (ELEM) at a given valid position (POS).

d. Deleting an element at a given valid position (POS).

e. Exit

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int size = 0;
void createArray();
void displayArray();
void insertElement();
void deleteElement();

void main()
{
    int choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Create Array\n2. Display Array\n3. Insert Element\n4. Delete Element\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createArray();
            break;

        case 2:
            displayArray();
            break;

        case 3:
            insertElement();
            break;

        case 4:
            deleteElement();
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong selection!!! Try again!!!\n");
        }
    }
}

void createArray()
{
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    size = n;
}

void displayArray()
{
    int i;
    printf("The elements of the array are: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement()
{
    int i, pos, elem;
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the element to be inserted: ");
    scanf("%d", &elem);
    if (pos > size)
    {
        printf("Invalid position\n");
        return;
    }
    for (i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = elem;
    size++;
}

void deleteElement()
{
    int i, pos;
    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);
    if (pos > size)
    {
        printf("Invalid position\n");
        return;
    }
    for (i = pos - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
