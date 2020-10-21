
#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}Node;
 class Stack{

  Node *top;
 public:
  Stack(){
      top==NULL;
  }
   bool isEmpty();

    void push(int x);
    int pop();
    int size();
    void display();

};

bool Stack::isEmpty(){
    if (top==NULL){
        return true;
    }
    return false;
}
void Stack ::push(int b ){
  Node *newNode;
  newNode = new Node;
  newNode->data=b;
  newNode->next=top;
  top=newNode;

}
int Stack ::pop( ){
  if(isEmpty()){
      return 0;
  }
     int y;
     Node *temp;
     temp=top;
     top=top->next;
     y=temp->data;

    delete temp;
    return y;

}
int Stack:: size(){
    int count=0;
    Node *temp;
    temp=top;
    while(temp!=NULL){
        temp=temp->next;
      count++;

    }
    return count;
}

void Stack::display(){
    Node *temp;
    temp=top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    cout<<endl;
     int v;
      v= s.pop();
  // cout<<"pooped element "<<v<<endl;
    cout<<s.size()<<endl;

 //   return 0;
}

