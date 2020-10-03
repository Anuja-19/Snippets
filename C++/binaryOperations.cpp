DESCRIPTION : 

queue::push()
push() function is used to insert an element at the back of the queue. The element is added to the queue container and the size of the queue is increased by 1.

queue::pop()
pop() function is used to remove an element from the front of the queue(oldest element in the queue). The element is removed to the queue container and the size of the queue is decreased by 1.


IMPLEMENTATION :
 
#include <iostream> 
#include <queue> 
using namespace std; 
  
int main() 
{ 
    // Empty Queue 
    queue<int> myqueue; 
    // Implementation of push() function
    myqueue.push(0); 
    myqueue.push(1); 
    myqueue.push(2); 
  
    // Printing content of queue 
    while (!myqueue.empty()) { 
        cout << ' ' << myqueue.front(); 
        
// Implementation of pop() function 
        myqueue.pop(); 
    } 
} 

'''
OUTPUT : 0 1 2
'''
