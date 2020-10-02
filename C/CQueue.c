#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int cqueue_arr[MAX];
int rear = -1;
int front = -1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main()
{
    int choice;
    int item;
    while(1)
    {
        printf("\n\n***** CIRCULAR QUEUE MENU *****\n\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display element at the front\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item to Insert : "); scanf("%d",&item); insert(item); break;
            case 2: printf("Element deleted is : %d",del()); break;
            case 3: printf("Element at front is : %d",peek()); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}

void insert(int item)
{
    if(isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1 && rear == -1)
        front++;
    rear = (rear+1)%MAX;
    cqueue_arr[rear] = item;
}

int del()
{
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    item = cqueue_arr[front];
    if(front == rear) // Queue has only 1 element
    {
        front = -1;
        rear = -1;
        return item;
    }
    front = (front+1)%MAX;
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return cqueue_arr[front];
}

int isEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if((rear+1)%MAX == front)
        return 1;
    else
        return 0;
}

void display()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Queue is : \n");
    int i = front;
    while(i != rear)
    {
        printf("%d ",cqueue_arr[i]);
        i = (i+1)%MAX;
    }
    printf("%d ",cqueue_arr[i]);
    printf("\n");
}
