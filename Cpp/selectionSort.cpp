// Selection Sort in C++, Time Complexity: O(n^2) 

#include <bits/stdc++.h>
using namespace std;

void displayElements(vector<long> vec, long size)  
{    
    for (long i = 0; i < size; i++)  
        cout << vec[i] << " ";  
    cout << "\n";  
}  

void selectionSort(vector<long> vec, long n)  
{  
    long i, j, min_index;  
  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_index = i;  
        for (j = i + 1; j < n; j++)  
        	if (vec[j] < vec[min_index])  
            	min_index = j;  
  
        // Swap the minimum element with the first element of the current array
        long temp = vec[min_index];
        vec[min_index] = vec[i];
        vec[i] = temp;
    }  
}  

int main()
{
	long n, x;
	cout << "Enter number of elements in the array: ";
	cin >> n;

	vector<long> vec(n);
	cout << "Enter the array elements now: \n";
	for(long i = 0; i < n; i++){
		cin >> x;
		vec.push_back(x);
	}

	cout << "Array before Selection Sort: \n";
	displayElements(vec, n);

	// performing Selection Sort
    selectionSort(vec, n);

    cout << "Array after Selection Sort: \n";
	displayElements(vec, n);

	return 0;
}