#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*root=NULL;

//Program to reverse a linked list

int main()
{
    int n,x,i;
    struct Node *t,*p=NULL,*r;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter the elements\n";

    for(i=0;i<n;i++)
    {
        cin>>x;
        t = new Node;
        t->data = x;
        if(root == NULL)
        root = t;
        t->next = NULL;
        if(p!=NULL)
        p->next=t;
        p = t;
    }

    t = root;
    cout<<"Elements before reversing are : ";
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    t = root;
    while(t!=NULL)
    {
        r = new Node;
        r->data = t ->data;
        if(t==root)
        r->next = NULL;
        else
        r->next = p;
        t = t->next;
        p=r;
    }

    cout<<"After reversing: ";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    return 0;
}