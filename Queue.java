A program that demonstrates queue in java is given as follows:
import java.util.LinkedList;
import java.util.Queue;
public class Example {
   public static void main(String[] args) {
      Queue<Integer> q = new LinkedList<>();
      q.add(6);
      q.add(1);
      q.add(8);
      q.add(4);
      q.add(7);
      System.out.println("The queue is: " + q);
      int num1 = q.remove();
System.out.println("The element deleted from the head is: " + num1);
System.out.println("The queue after deletion is: " + q);
int head = q.peek();
System.out.println("The head of the queue is: " + head);
int size = q.size();
System.out.println("The size of the queue is: " + size);
}
}

The output of the above program will be:
The queue is: [6, 1, 8, 4, 7]
The element deleted from the head is: 6
The queue after deletion is: [1, 8, 4, 7]
The head of the queue is: 1
The size of the queue is: 4
