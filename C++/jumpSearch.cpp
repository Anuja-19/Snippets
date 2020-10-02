// Jump search algorithm
// This algorithm finds the index of an element in a sorted array
// Time complexity : between Linear Search ( ( O(n) ) and Binary Search ( O (Log n) )

#include<iostream>
#include<math.h>

using namespace std;

int jumpSearch(int arr[], int length, int ele)
{
	int left, right;
	left = 0;
	right = sqrt(length);
	
	while(arr[right] <= ele && right < length)
	{
		left = right;
		right +=sqrt(length);
	}
	
	for(int i=left; i<right; i++)
	{
		if(arr[i] == ele)
		{
			return i+1;
			break;
		}
	}
	
	return -1;
}

int main()
{
	int ar[10],i,n;
	int ele;
	
	cout<<"Number of elements: ";
	cin>>n;
	cout<<"Enter array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	cout<<"Entered array elements: ";
	for(i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the element to be search: ";
	cin>>ele;
	
	int result = jumpSearch(ar, n, ele);
	
	cout<<"Result is: "<<result;
	
	return 0;
}
