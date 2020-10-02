#include<stdio.h>
#include<stdlib.h>

/* #define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main()
{
    int choice;
    int item;
    while(1)
    {
        printf("\n\n***** STACK MENU *****\n\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item to be pushed : "); scanf("%d",&item); push(item); break;
            case 2: item = pop(); printf("Item popped is : %d",item); break;
            case 3: printf("Item at top is : %d",peek()); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}

void push(int item)
{
    if (isFull())
    {
        printf("Overflow!\n");
        return;
    }
    stack_arr[++top] = item;
}

int pop()
{
    if (isEmpty())
    {
        printf("Underflow!\n");
        exit(1);
    }
    int item = stack_arr[top--];
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("Underflow!\n");
        exit(1);
    }
    return stack_arr[top];
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAX-1)
        return 1;
    else
        return 0;
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements are : \n");
    for(int i=top ; i>=0 ; i--)
        printf("%d ",stack_arr[i]);
    printf("\n");
} */

// LINKED LIST IMPLEMENTATION
struct node
{
    int info;
    struct node *link;
}*top = NULL;

void push(int item);
int pop();
int peek();
int isEmpty();
void display();

int main()
{
    int choice;
    int item;
    while(1)
    {
        printf("\n\n***** STACK MENU *****\n\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item to be pushed : "); scanf("%d",&item); push(item); break;
            case 2: item = pop(); printf("Item popped is : %d",item); break;
            case 3: printf("Item at top is : %d",peek()); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}

void push(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->link = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    int item;
    if(isEmpty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    temp = top;
    item = temp->info;
    top = top->link;
    free(temp);
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Empty Stack!\n");
        exit(1);
    }
    return top->info;
}

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *ptr = top;
    if(isEmpty())
    {
        printf("Empty Stack!\n");
        return;
    }
    printf("Stack elements : \n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
