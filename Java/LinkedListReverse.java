//Code snippet to reverse a linked list. Only includes the method.

public Node reverse(Node head) {
        Node previous = null;
        Node current = head;
        Node after = null; 
        while(current != null) {
            after = current.next;
            current.next = previous;
            previous = current;
            current = after;
        }

        head = previous;
        return head;
    }
