#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *add_at_beg(struct node *start, int data);
struct node *add_at_end(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *rev(struct node *start);

int main()
{
    struct node *start = NULL;
    int choice, data, pos, item;
    while(1)
    {
        printf("\n\n********** LINKED LIST MENU **********\n\n");
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n");

        printf("Enter Choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start = create_list(start); break;

            case 2: display(start); break;

            case 3: count(start); break;

            case 4: printf("Enter element to search : "); scanf("%d",&data); search(start,data); break;

            case 5: printf("Enter element to insert : "); scanf("%d",&data); start = add_at_beg(start,data); break;

            case 6: printf("Enter element to insert : "); scanf("%d",&data); start = add_at_end(start,data); break;

            case 7: printf("Enter element to insert : "); scanf("%d",&data); printf("Enter element after which to insert : "); scanf("%d",&item); start = addafter(start,data,item); break;

            case 8: printf("Enter element to insert : "); scanf("%d",&data); printf("Enter element before which to insert : "); scanf("%d",&item); start = addbefore(start,data,item); break;

            case 9: printf("Enter element to insert : "); scanf("%d",&data); printf("Enter position at which to insert : "); scanf("%d",&pos); start = addatpos(start,data,pos); break;

            case 10: printf("Enter element to delete : "); scanf("%d",&data); start = del(start,data); break;

            case 11: start = rev(start); break;

            case 12: exit(1);

            default:printf("Wrong choice!\n");
        }
    }
    return 0;
}

struct node *create_list(struct node *start)
{

}

void display(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *p = start;
    while(p != NULL)
    {
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n\n");
}

void count(struct node *start)
{
    struct node *p = start;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        p = p->link;
    }
    printf("No. of elements are : %d \n\n",cnt);
}

void search(struct node *start, int item)
{
    struct node *p = start;
    int pos=1;
    while(p != NULL)
    {
        if(p->info == item)
        {
            printf("Item %d found at position %d\n",item,pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item %d not found in list! \n\n",item);
}

struct node *add_at_beg(struct node *start, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
}

struct node *add_at_end(struct node *start, int data)
{
    struct node *p;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    while(p->link != NULL)
        p = p->link;

    p->link = temp;
    temp->link = NULL;
    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    // data is the new value to be inserted
    // item is the value after which the node has to be inserted
    struct node *temp;
    struct node *p = start;
    while(p != NULL)
    {
        if(p->info == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *p,*temp;
    if(item == start->info)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = start;
        start = temp;
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}

struct node *addatpos(struct node *start, int data, int pos)
{
    struct node *p,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    if(pos==1)
    {
        temp->link = start;
        start = temp;
        return start;
    }
    for(int i=1 ; i<=pos && p!=NULL ; i++)
        p = p->link;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        temp->link = p->link;
        p->link = temp;

    }
    return start;
}

struct node *del(struct node *start, int data)
{
    struct node *temp,*p;
    if(start == NULL)
    {
        printf("List is empty!\n");
        return start;
    }
    if(start->info == data)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    p = start;
    while(p != NULL)
    {
        if(p->link->info == data)
        {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found\n",data);
    return start;
}

struct node *rev(struct node *start)
{
    struct node *prev,*ptr,*next;
    prev = NULL;
    ptr = start;
    while(ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}
