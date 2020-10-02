#include<bits/stdc++.h>
using namespace std;


class node{
    public:
        int data;
        node* next;
};

class myLinkedList{
    public:
        node* head;
        myLinkedList()
        {
            head=NULL;
        }

    void insertAtTop(int data)
    {
        node* tempNode = new node();
        tempNode->data=data;
        tempNode->next=head;
        head=tempNode;
    }
    void insertAtEnd(int data)
    {
        node* tempNode = new node();
        node* initialNode =head;

        tempNode->data=data;
        tempNode->next=NULL;

        if(initialNode==NULL)
        {
            head=tempNode;
            return;
        }
        // else iterate till end of the current ll.
        while(initialNode->next!=NULL)
        {
            initialNode=initialNode->next;
        }
        // once we reach the end of node, link the next of last node to the new node.
        initialNode->next=tempNode;
        return;
    }
    void display()
    {   node* temp =head;
        if(temp==NULL)
        {
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insertAfter(int data,int index)
    {
        node* current =head;
        for(int i=0;i<index-1;++i)
        {
            current=current->next;
        }
        node* temp= new node();
        temp->data = data;
        temp->next = current->next;
        current->next=temp;
    }

    void deleteKey(int key)
    {
        node* temp= head;
        node* prev;

        // if head holds the key.
        if(temp!=NULL and temp->data==key)
        {
           head=temp->next;
           free(temp);
           return;
        }
        while(temp!=NULL & temp->data!=key)
        {
            prev = temp;
            temp=temp->next;

        }
        if(temp==NULL)
        {
            cout<<"Key not found in current linked list."<<"\n";
        }
        //else.
        prev->next = temp->next;
        free(temp);
    }

    void reverse()
    {
        node* current =head;
        node* previous = NULL;
        

        while(current!=NULL)
        {   node* nextLink = current->next;
            current->next = previous;
            previous = current;
            current = nextLink;
        }
        head = previous;
    }


};

 node* merge(node* l1, node* l2)
{
    node* temphead;
    node* temptail;
    node* a; node*  b;
    if(l1->data > l2->data)
    {
        temphead = l2;
        temptail =l2;
         a = temphead->next;

         b = l1;
        
    }else{
        temphead = l1;
        temptail =l1;
         a = temphead->next;

         b = l2;
    }

    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            temptail->next=a;
            
            temptail=a;
            a = a->next;
        }else{
            temptail->next=b;
            temptail=b;
            b=b->next;
        }

    }
    return temphead;

}





int main()
{

	myLinkedList l1,l2;
	//1. Insert at last
	for (int i = 1; i <=5; ++i)
	{
		l1.insertAtEnd(i);
	}
	for (int i = 6; i <=10; ++i)
	{
		l2.insertAtTop(i);
	}
	
	cout<<"Linked list 1 is: "<<endl;
	l1.display();  // 1- 2 - 3 - 4 - 5
    cout<<endl;
	cout<<"Linked list 2 is: "<<endl;;
	l2.display(); 
	cout<<endl;
    // This Class also contain many other operations which you can do in singly linked list C++.
	
	
    return 0;
}