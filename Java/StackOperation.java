// Java code for stack operation in an Array
package Snippets.Java;
import java.util.*;

public class StackOperation
{
    // Pushing element on the top of the stack
    static void stackPush(Stack<Integer> stack)
    {
        for(int i = 0; i < 5; i++)
        {
            stack.push(i);
        }
    }

    // Popping element from the top of the stack
    static void stackPop(Stack<Integer> stack)
    {
        System.out.println("Pop Operation of Stack:");

        for(int i = 0; i < 5; i++)
        {
            Integer number = (Integer) stack.pop();
            System.out.println(number);
        }
    }

    // Displaying element on the top of the stack
    static void stackPeek(Stack<Integer> stack)
    {
        Integer element = (Integer) stack.peek();
        System.out.println("Element on stack top: " + element);
    }

    // Searching element in the stack
    static void stackSearch(Stack<Integer> stack, int element)
    {
        Integer position = (Integer) stack.search(element);

        if(position == -1) {
            System.out.println("Element not found");
        }
        else {
            System.out.println("Element is found at position: " + position);
        }
    }


    public static void main (String[] args)
    {
        Stack<Integer> stack = new Stack<Integer>();
        stackPush(stack);
        stackPop(stack);
        stackPush(stack);
        stackPeek(stack);
        stackSearch(stack, 2);
        stackSearch(stack, 6);
    }
}

/*
OutPut:

Pop Operation of Stack:
4
3
2
1
0
Element on stack top: 4
Element is found at position: 3
Element not found

*/

