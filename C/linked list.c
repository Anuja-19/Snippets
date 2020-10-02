#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int element;
	struct Node*next;
};
struct Node*First=NULL;
struct Node*Last=NULL;
void reverse();
int sum();
int count();
int Delyeet(int );
void desiredInsert(int ,int );
void Insert(int n)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->element=n;
	if(First==NULL)
	{		
		First=Last=ptr;
		ptr->next=NULL;
		return;
	}
	else
	{
		Last->next=ptr;
		ptr->next=NULL;
		Last=ptr;
		return;	
	}
}
struct Node *Search(int c)
{
	struct Node*pt;
	if(First==NULL)
	return NULL;
	if(First==Last)
	return First;
	for(pt=First;pt!=Last;pt=pt->next)
	{
		if(pt->element==c)
		{
		return pt;
		break;
	}	
		if(pt->element==Last->element)
		return Last;

}
}
int Delete(int y)
{
	int o;
	struct Node*Loc;
	struct Node*temp;
	Loc=Search(y);
	if(Loc==NULL)
	return(-9999);
	if(Loc==First)
	{
		if(First==Last)
		{
		o=First->element;
		First=NULL;
		Last=NULL;
		return o;
	}
		else
		{
		o=First->element;
		First=First->next;
		return o;
	}
	}
	for(temp=First;temp->next!=Loc;temp=temp->next);
	temp->next=Loc->next;
	if(Loc==Last)
	{
		Last=temp;
		return(Loc->element);
	}	 
}
void display()
{
	struct Node*ptr;
	if(First==NULL)
	{
	printf("\nEmpty List");
	return;
}
	if(First==Last)
	{
	printf("\t %d",First->element);
	return;
}
	for(ptr=First;ptr!=Last;ptr=ptr->next)
	printf("\t%d",ptr->element);
	
	 printf("\t%d",Last->element);
}
int main()
{
	int choice,op=1,num,num2;
	while(op)
	{
	printf("Enter your choice");
	printf("\n 1=Insert \t 2=Delete \n 3=Display \t 4=Reverse list \n 5=Sum \t \t 6=Count \n 7=Delyeet \t 8=desi");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("\n Enter the number to be inserted");
					scanf("%d",&num);
					Insert(num);
					break;
				}
			case 2:
				{
					int l;
					printf("\n Enter the number to be deleted");
					scanf("%d",&num);
					l=Delete(num);
					if(l==-9999)
					printf("\n Empty list lol");
					else
					printf("\n Link removed successfully=%d",&Last);
					break;				
				}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					reverse();
					break;
				}
			case 5:
				{
					int sum2;
					sum2=sum();
					printf("Sum=%d",sum2);
					break;
				}
			case 6:
				{
					int k;
					k=count();
					printf("Count=%d",k);
					break;
				}
			case 7:
				{
					int c,nu;
					display();
					printf("\n Enter the node value to be deleted");
					scanf("%d",&nu);
					c=Delyeet(nu);
					break;
				}
			case 8:
				{
					int val,pos;
					printf("Enter the value to be inserted");
					scanf("%d",&val);
					display();
					printf("\n Enter the node value after which it is to be inserted");
					scanf("%d",&pos);
					desiredInsert(pos,val);
					break;
				}
			default:
					{
					printf("\n Invalid input");
					break;
				}
		}
		fflush(stdin);
		printf("\n Do you wish to continue 1=Yes,0=No");
		scanf("%d",&op);
}
}
void reverse()
{
	struct Node *curr=First;
	struct Node *prev=NULL;
	struct Node *n=NULL;
	struct Node *temp;
	while(curr!=NULL)
	{
		if(curr==First)
		{
			temp=First;
		}
		n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}
	First=prev;
	Last=temp;
}
int sum()
{
	struct Node*p;
	int sum1=0;
	for(p=First;p!=Last;p=p->next)
	sum1+=p->element;
	sum1+=Last->element;
	return sum1;
}
int count()
{
	int c=0;
	struct Node*p;
	for(p=First;p!=Last;p=p->next)
	c++;
	c++;
	return c;
}
int Delyeet(int n)//n=specified node INFO
{
	int z;
	struct Node*lptr;//declaring the pointer to structure node
	lptr=Search(n);
	z=lptr->next->element;
	lptr->next=lptr->next->next;
	return z;
}
void desiredInsert(int n,int value)//n=specified node INFO,value=data to be filled in the node
{
	struct Node*lptr;//declaring the pointer to structure node
	lptr=Search(n);
	struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->element=value;
	if(lptr==Last)
	{
		Last->next=ptr;
		ptr->next=NULL;
		Last=ptr;
		return;
	}
	else//anywhere else
	{
		ptr->next=lptr->next;
		lptr->next=ptr;
		return;
}		
}
