#include<iostream> 
 
using namespace std;   
 
struct  Node
{ 
    int value; 
    Node *next; 	
}; 
 
class Stack{   

  private:    
      Node *Top;  

  public: 
       Stack(){   
           Top=NULL;
       }   

       void Push(int val){  

           	Node *temp_node=new Node();  

           	if(!temp_node){ 
    	        	cout<<"Heap Overflow\n";      //Overflow condition not enough memory to allocate  
              return;
           	}  

            temp_node->value=val;
           	temp_node->next=Top; 
    	       Top=temp_node;
        }  

        void Pop(){   

          	if(Top==NULL){    
    	         	 cout<<"Underflow\n";     //Underflow condition;
    	        	  return;          
          	}   

           Node *temp=Top;  
    	      Top=Top->next; 
    	      temp->next=NULL; 
           free(temp);
        }  

        bool is_empty(){   
            
               return Top==NULL;
        } 

        int Peek(){ 

          	if(Top) 
    	         return Top->value; 
        }  

        void Display(){   

           	Node*temp=Top;             //To Preserve Top  

           	while(temp!=NULL){   
                  cout<<temp->value<<" "; 
    	       	     temp=temp->next;
           }

        }

}; 

int main(){  

    Stack S;  

    for(int i=0;i<6;++i){ 

       	S.Push(i+1); 
    }  

    cout<<"Stack is ";  

    S.Display(); 

    cout<<'\n';  

    S.Pop(); 

    cout<<"Top is ";  

    cout<<S.Peek()<<'\n'; 

    for(int i=0;i<5;++i){ 

    	    S.Pop();
    }  

    if(S.is_empty())  
    	 cout<<"Stack is empty";  
    else  
    	cout<<"Stack have elements";

   return 0;

}



