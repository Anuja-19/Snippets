
#include <iostream>
# define max 10
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}Node;
 class Stack{

    int arr[max];
    int top;
     public:
    Stack(){
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(int );
    int pop();
    int size();
    void display();
};

bool Stack::isEmpty(){
    if (top==-1){
        return true;
    }
    return false;
}
bool Stack::isFull(){
    if (top==max-1){
        return true;
    }
    return false;
}
void Stack ::push(int b ){
    if(isFull()){
        cout<<"Cannot enter as the stack is full";
    }
    else{
    top++;
    arr[top]=b;
}}
int Stack ::pop( ){
   if(isEmpty()){
       return 0;
   }else{
   int x;
   x=arr[top];
   top--;
   return(x);
   }
}
int Stack:: size(){
    int i;
     for ( i=0;i<=top;i++);
    return i;
}

void Stack::display(){
    for (int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
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
    int v= s.pop();
   cout<<"pooped element "<<v<<endl;
    cout<<s.size()<<endl;
    s.display();
    return 0;
}

