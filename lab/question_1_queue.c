// Queue using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];

int front = -1, rear = -1;

void insert(int);

int delete();

int peek();

void display();


int  main(){
    int choice, val;

    while(1){
        printf("\n\n***** MENU *****\n");
        printf("1. Insert\n2. Delete\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d", &val);
                    insert(val);
                    break;

            case 2: val = delete();
                    if(val != -1)
                        printf("The deleted element is %d\n", val);
                    break;

            case 3: val = peek();
                    if(val != -1)
                        printf("The front element is %d\n", val);
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Wrong selection!!! Try again!!!\n");
        }
    }

    return 0;
}


void insert(int val){
    if(rear == MAX-1)
        printf("Queue is full!!! Insertion is not possible!!!\n");
    else{
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
    }
}


int delete(){
    int val;
    if(front == -1 || front > rear){
        printf("Queue is empty!!! Deletion is not possible!!!\n");
        return -1;
    }
    else{
        val = queue[front];
        front++;
        if(front > rear)
            front = rear = -1;
        return val;
    }
}


int peek(){
    if(front == -1 || front > rear){
        printf("Queue is empty!!!\n");
        return -1;
    }
    else{
        return queue[front];
    }
}


void display(){
    int i;
    if(front == -1 || front > rear)
        printf("Queue is empty!!!\n");
    else{
        printf("Queue elements are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

