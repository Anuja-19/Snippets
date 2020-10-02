// C program to sort the elements of an array in ascending order.
// Code written by Sayan Manna

#include <stdio.h>

int main() {
    int sizeOfArray;
    scanf("%d",&sizeOfArray);
    int arr[sizeOfArray];
    for(int i = 0; i < sizeOfArray; i++)
        scanf("%d", &arr[i]);
    
    insertionSort(arr, sizeOfArray);
    printArray(arr, sizeOfArray);

    return 0;
}

void insertionSort(int arr[], int sizeOfArray) {
    int i, key, j;
    for(i = 1; i < sizeOfArray; i++) {
        key = arr[i];
        j = i - 1;
        /*
        Moving elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position
        */
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j -= 1;
       }
       arr[j + 1] = key;
    }  
}
void printArray(int arr[], int sizeOfArray) {
    for(int i = 0; i < sizeOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
Sample Input:
5
11 2 4 5 7

Sample Output:
2 4 5 7 11
*/