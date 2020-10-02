import java.util.*;

public class BubbleSort {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter the number of elements in array:");

		int count = input.nextInt();		//input count
		input.nextLine();
		
		System.out.println("Enter the array elements to be sorted:");

		int[] arr = new int[count];
		Scanner numScanner = new Scanner(input.nextLine());
		for (int i = 0; i < count; i++) {
			if (numScanner.hasNextInt()) {
				arr[i] = numScanner.nextInt();
			} else {
				System.out.println("You didn't provide enough numbers");
				break;
			}
		}		//input array
		
		System.out.println("Array before Sorting:");
		
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		
		bubbleSort(arr);		// call bubble sort method

		System.out.println("Array After Bubble Sort:");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}

		input.close();

	}

	static void bubbleSort(int[] arr) {
		int n = arr.length;
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < (n - i); j++) {
				if (arr[j - 1] > arr[j]) {
					// swap elements
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}

			}
		}

	}
}
