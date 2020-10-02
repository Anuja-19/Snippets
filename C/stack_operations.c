#include<stdio.h>

#define N 1000

int stack[N];
int top=-1;


int isempty()
{
    if(top!=-1)
        return 0;
    else return 1;
}
int isfull()
{
    if(top<N-1)
        return 0;
    else
        return 1;
}

void push()
{
    printf("Enter the element to push into the Stack\n");
    int temp;
    scanf("%d",&temp);
    if(!isfull())
    {


    stack[++top]=temp;
    printf("Susccesfully Pushed the Element into the Stack\n");
    }
    else
        printf("Stack is Full\n");


}



void pop()
{   if(!isempty())
    {


    int ele=stack[top--];
    printf("Element Popped :%d\n",ele);
    }
    else
        printf("No elements are present inside the Stack\n");
}

void Display()
{   printf("Elements Present inside the Stack are :\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d  ",stack[i]);
    }
    printf("\n");

}
void count()
{
    printf("The total Number of Elements inside the Stack are : %d\n",top+1);
}
int main()
{   while(1)
    {


    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Count the Number of Elements inside the Stack\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    int n;
    scanf("%d",&n);
    if(n==4)
        break;
    switch(n)
    {
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:count();
        break;
        case 4:Display();
        break;
        default:printf("Invalid Option\n");
    }


    }
}

