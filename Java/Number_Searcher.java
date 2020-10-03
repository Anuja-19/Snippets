import java.util.Scanner;
//This code computes the index location of the searched number in the user-specified array
public class Number_Searcher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int num = sc.nextInt();
        int arr[] = new int[num];
        System.out.println("Enter numbers: ");
        for(int i = 0; i < num; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the number you want to search: ");
        int search = sc.nextInt();
        boolean isFound = false;
        for(num = 0; num < arr.length; num++) {
            if (arr[num] == search) {
                System.out.println(search + " is present at index " + num);
                isFound = true;
                break;
            }
        }
        if(isFound == false){
            System.out.println(search + " is not present in the array");
        }
        sc.close();
    }
}
