#include<stdio.h>
#include<stdlib.h>

/* #define MAX 10

int queue_arr[MAX];
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
        printf("\n\n***** QUEUE MENU *****\n\n");
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
            case 2: item = del(); printf("Item deleted is : %d",item); break;
            case 3: printf("Item at front is : %d",peek()); break;
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
    if(front == -1)
        front = 0;
    queue_arr[++rear] = item;
}

int del()
{
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    item = queue_arr[front];
    front++;
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return queue_arr[front];
}

int isEmpty()
{
    if(front == -1 || front == rear+1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == MAX-1)
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
    for(int i=front ; i<=rear ; i++)
        printf("%d ",queue_arr[i]);
    printf("\n");
} */

// LINKED LIST IMPLEMENTATION
struct node
{
    int info;
    struct node *link;
}*front = NULL, *rear = NULL;

void insert(int item);
int del();
int peek();
int isEmpty();
void display();

int main()
{
    int choice;
    int item;
    while(1)
    {
        printf("\n\n***** QUEUE MENU *****\n\n");
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
            case 2: item = del(); printf("Item deleted is : %d",item); break;
            case 3: printf("Item at front is : %d",peek()); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}

void insert(int item) // IMP
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Unavailable!\n");
        return;
    }
    temp->info = item;
    temp->link = NULL;
    if(front == NULL)
        front = temp;
    else
        rear->link = temp;
    rear = temp;
}

int del()
{
    struct node *temp;
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    temp = front;
    item = temp->info;
    front = front->link;
    free(temp);
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return front->info;
}

int isEmpty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *ptr;
    ptr = front;
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements : \n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
