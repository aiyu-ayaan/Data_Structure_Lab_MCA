#include <stdio.h>
#include <stdlib.h>

void changeValue(int **ptr, int val)
{
    **ptr = val;
}

void main()
{
    int *a = (int *)malloc(sizeof(int));
    printf("Enter value for a :- ");
    scanf("%d", a);
    int *ROOT = a;
    int **d_ptr = &ROOT;

    changeValue(&ROOT, 10000);
    // *ROOT = 10000; // with function
    // print d_ptr
    printf("Value of * Root = %d \n", (*ROOT));
    printf("Value of Root = %d \n", ROOT);
    printf("Value of A = %d \n", a);
    printf("value of *A = %d\n", *a);
    
}
