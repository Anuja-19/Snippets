public class Queue<E> {
    class Node {
        E data;
        Node next;

        public Node (E obj) {
            data = obj;
            next = null;
        }
    }

    private Node head = null;
    private Node tail = null;

    public void enqueue(E obj) {
        Node temp = new Node(obj);
        if(head==null) {
            head = tail = temp;
        }
        tail.next=temp;
        tail=temp;
    }

    public E dequeue() {
        E temp = head.data;
        head = head.next;
        return temp;
    }

    public void display() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }
}
