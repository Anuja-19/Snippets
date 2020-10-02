#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* next;
};
struct node *head=NULL,*newnode,*temp;

void create(){
int choice=1;  
do{
  newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data: ");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head == NULL)
head=temp=newnode;
else{
temp->next=newnode;
temp=newnode;
}
printf("\nDo you want to enter more?(1/0): ");
scanf("%d",&choice);
}while(choice!=0);
}

void insert_beg(){
newnode=(struct node*)malloc(sizeof(struct node));  
printf("\nEnter data in beginning: ");
scanf("%d",&newnode->data);  
newnode->next=head;
head=newnode;
}  

void insert_end(){
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data at end: ");
scanf("%d",&newnode->data);
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
temp=newnode;
}

int count(){
  int c;
  temp=head;
  while(temp!=NULL){
  c++;
  temp=temp->next;
  }
  return c;
}

void insert_mid(){
int pos,i;  
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data in new node: ");
scanf("%d",&newnode->data);
newnode->next=NULL;  
printf("\nEnter position after which you want to insert new node: ");
scanf("%d",&pos);
if(pos>count())
printf("\nInvalid position");
else{
  temp=head;
  for(i=1;i<pos;i++){
    temp=temp->next;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  temp=newnode;
}
}

void del_beg(){
if(head==NULL)
printf("\nList is empty");
else{
  printf("\n%d is deleted from linked list",head->data);
  temp=head;
  head=head->next;
  free(temp);
}
}
void del_mid(){
int pos,i;
struct node *temp1;  
if(head==NULL)
printf("\nList is empty");
else{
  printf("\nEnter position of node to be deleted: ");
  scanf("%d",&pos);
  if(pos>count())
  printf("\nInvalid position");
  else{
    temp=head;
    for(i=1;i<pos-1;i++)
    temp=temp->next;
  }
  temp1=temp->next;
  temp->next=temp->next->next;
  free(temp1);  
}
}
void del_end(){
int i; 
if(head==NULL)
printf("\nList is empty");
else{
  temp=head;
  while(temp->next->next!=NULL)
  temp=temp->next;
}
free(temp->next);
temp->next=NULL;
}

void display(){
if(head==NULL)
printf("\nLinked list is empty");
else{
  temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
}
int main() {
  int choice;
  do{
  printf("\nMenu");
  printf("\n1.Creation");
  printf("\n2.Insertion in beginning");
  printf("\n3.Insertion at end");
  printf("\n4.Insertion in mid");
  printf("\n5.Deletion from beginning");
  printf("\n6.Deletion from end");
  printf("\n7.Deletion from mid");
  printf("\n8.Display");
  printf("\n9.Exit");
  printf("\nEnter your choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:create();
           break;
    case 2:insert_beg();
           break;
    case 3:insert_end();
           break;
    case 4:insert_mid();
           break;              
    case 5:del_beg();
           break;
    case 6:del_end();
           break;
    case 7:del_mid();
           break;              
    case 8:display();
           break;
    case 9:printf("\nExited.");
           break;
    default:break;
  }
  }while(choice!=9);
return 0;
}