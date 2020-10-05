#include <stdio.h>

void heapsort(int a[], int n) {
   int i = n / 2, parent, child, t;
   
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
    } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
	}
      parent = i;
      child = i * 2 + 1;
    while (child < n) {
    	if ((child + 1 < n)  &&  (a[child + 1] > a[child]))
              child++;
   	    if (a[child] > t) {
			a[parent] = a[child];
			parent = child;
			child = parent * 2 + 1;
		}else {
			break;
		}
	}
      a[parent] = t;
   }
}

void printArray(int arr[], int size){
	int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
	printf("\n");
}

int main(){
	int arr[] = {8, 5, 2, 6, 1, 9, 7, 10, 4, 3};
	
	heapsort(arr, 10);
	printArray(arr, 10);
}
