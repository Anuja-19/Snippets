// Insertion Sort in Java, Time Complexity: O(n^2)

import java.io.*;
import java.util.*;

public class InsertionSort { 
   
    static void displayElements(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n; ++i) 
            System.out.print(arr[i] + " ");
        System.out.println(); 
    }
    
    void insertion_sort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 1; i < n; i++) { 
            int key = arr[i]; 
            int j = i - 1; 
  
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j -= 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        
        int n;
        System.out.println("Enter the number of array elements: ");
        n = sc.nextInt();
        
        int arr[] = new int[n];
        System.out.println("Enter the array elements: ");
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        
        System.out.println("Array elements before Insertion Sort: ");
        displayElements(arr); 
        
        InsertionSort obj = new InsertionSort(); 
        obj.insertion_sort(arr); 
  
        System.out.println("Array elements after Insertion Sort: ");
        displayElements(arr); 
    } 
}