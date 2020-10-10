using System;
using System.Collections.Generic;
using System.Linq;

namespace ReverseLinkedList
{
    class ReverseLinkedList
    {
        static void Main(string[] args)
        {
            Test(0, 100);
        }

        //Test my implementation against the one built into Enumerable
        static void Test(int start, int end)
        {
            LinkedList<int> testList0 = new LinkedList<int>();
            LinkedList<int> testList1 = new LinkedList<int>();
            for(var i = start; i < end; i++)
            {
                testList0.AddLast(i);
                testList1.AddLast(i);
            }
            
            Console.WriteLine("Not Reversed:");
            foreach(var item in testList0)
                Console.Write(string.Format("{0} ", item));
            Console.WriteLine();

            var startTime = DateTime.Now;
            Reverse(ref testList0);
            Console.WriteLine("\nReversed (my implementation):");
            foreach(var item in testList0)
                Console.Write(string.Format("{0} ", item));
            Console.WriteLine(string.Format("\nTime taken: {0}s", (DateTime.Now - startTime).TotalSeconds));

            startTime = DateTime.Now;
            Console.WriteLine("\nReversed (Enumerable implementation):");
            foreach(var item in testList1.Reverse())
                Console.Write(string.Format("{0} ", item));
            Console.WriteLine(string.Format("\nTime taken: {0}s\n", (DateTime.Now - startTime).TotalSeconds));
        }

        //Generic function that reverses the linked list
        static void Reverse<T>(ref LinkedList<T> list)
        {
            if(list.Count > 0)
            {
                var head = list.First;
                while (head.Next != null)
                {
                    var next = head.Next;
                    list.Remove(next);
                    list.AddFirst(next.Value);
                }
            }
        }
    }
}
