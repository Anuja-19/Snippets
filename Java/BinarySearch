import java.io.*;
import java.util.*;
class BinarySearch { 
    public static void main(String args[]) throws IOException
    { 
        Scanner sc=new Scanner(System.in);
        BinarySearch ob = new BinarySearch();
        int n;
        n=sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        int x = 10; 
        int result = ob.binarySearch(arr, 0, arr.length - 1, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at index " + result); 
    }
   
    int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
  
            if (arr[mid] == x) 
                return mid; 
   
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
  
            return binarySearch(arr, mid + 1, r, x); 
        } 
   
        return -1; 
    } 
  
} 

