import java.util.Arrays;
import java.util.Scanner;

public class HeapSort {

    /**
     * Java method to heapify subtree with root node i
     * 
     * @param int[] arr : array
     * @param int   n : size of heap
     * @param int   i : node
     */
    public static void heapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }

    /**
     * Java method to sort array using heap sort
     * 
     * @param int[] arr : array
     */
    public static void heapSort(int arr[]) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.println("Enter the number of array elements: ");
        n = sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the array elements: ");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        System.out.println("Original array : " + Arrays.toString(arr));
        heapSort(arr);
        System.out.println("Sorted array : " + Arrays.toString(arr));
    }
}
