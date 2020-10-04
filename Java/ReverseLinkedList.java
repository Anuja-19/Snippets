

class LinkedList { 
  
     Node head; 
  
    static class Node { 
  
        int data; 
        Node next; 
  
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    /* Function to reverse the linked list */
    Node reverse(Node node) 
    { 
        Node prev = null; 
        Node current = node; 
        Node next = null; 
        while (current != null) { 
            next = current.next; 
            current.next = prev; 
            prev = current; 
            current = next; 
        } 
        node = prev; 
        return node; 
    } 
  
    // prints content of double linked list 
    void printList(Node node) 
    { 
        while (node != null) { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
    } 
  
    public static void main(String[] args) 
    { 
        LinkedList list = new LinkedList(); 
        list.head = new Node(85); 
        list.head.next = new Node(15); 
        list.head.next.next = new Node(4); 
        list.head.next.next.next = new Node(20); 
  
        System.out.println("Given Linked list"); 
        list.printList(list.head); 
        list.head = list.reverse(list.head); 
        System.out.println(""); 
        System.out.println("Reversed linked list "); 
        list.printList(list.head); 
    } 
} 



/* Basically is uses 3 pointer method to reverse a node prev curr next
   previous and current replaces themselves in normal swapping and then the next gives you a way to go to
   next element without falling in an infinite loop after swapping we put curr=next and next=curr.next */