// Program to find max subarray sum using kandanes algorithm.
#include <iostream>
using namespace std;
int kandane(int arr[] , int n);
int main()
{
	// getting the length of arr followed by arr elements.
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max_sum_subarray = kandane(arr , n );
	cout<<"max_sum_subarray = " << max_sum_subarray ; 	
}

int kandane(int arr[] , int n)
{
	int max_so_far = 0;
	int max_upto_here = 0;
	for (int i = 0; i < n; i++)
	{
		max_upto_here += arr[i];
		if (max_upto_here<0)
		{
			max_upto_here = 0;
		}
		if (max_so_far < max_upto_here)
		{
			max_so_far = max_upto_here;
		}	
	}
	return max_so_far;
}