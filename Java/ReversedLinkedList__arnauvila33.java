

public class ReversedLinkedList__arnauvila33 {
	
	static Node head;
	
	static class Node{
		int data;
		public Node next;
		Node(int data){
			this.data=data;
			next=null;
		}
	}
	
	/**
	 * Recursive method to reverse a Linked List. 
	 * @param node The head node of the linked list.
	 * @return the inversed linked list.
	 */
	private static Node reverseList(Node node) {
		if (node == null || node.next == null)  
            return node;  
  
       
        Node rest = reverseList(node.next);  
        node.next.next = node;  
  
      
        node.next = null;  
  

        return rest;  
	}
	
	/**
	 * Method to print the list passed.
	 * @param head the head of the list to print.
	 */
	private static void print(Node head) {
		Node temp = head;  
        while (temp != null) {  
            System.out.print(temp.data + " ");  
            temp = temp.next;  
        }  
        System.out.println(); 
	}
	
	/**
	 * Main method to test the reversedList method.
	 * @param args argument passed.
	 */
	public static void main(String[] args) {
		ReversedLinkedList__arnauvila33 list=new ReversedLinkedList__arnauvila33();
		list.head=new Node(15);
		list.head.next = new Node(50); 
        list.head.next.next = new Node(100); 
        list.head.next.next.next = new Node(300); 
        
        System.out.print("Linked List: "); 
        list.print(list.head); 
        
        //Reversing the list
        list.head = list.reverseList(list.head); 
        
        System.out.println(""); 
        System.out.print("Linked List Reversed: "); 
        list.print(list.head); 
		
	}
}
