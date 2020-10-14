#include <stdio.h>

int main()
{
	//length of arr
	int length;
	scanf("%d",&length);
	
	int arr[length];
	//enter array elements
	for (int i = 0; i < length; i++)
	{
		scanf("%d",&arr[i]);
	}

	// max sum calculated so far
	int max_sum_sofar = 0;
	// max sum upto current element of arr
	int max_sum_upto_here = 0;

	for (int i = 0; i < length; i++)
	{
		max_sum_upto_here += arr[i];
		if (max_sum_upto_here < 0)
		{
			max_sum_upto_here = 0;
		}
		if (max_sum_sofar < max_sum_upto_here)
		{
			max_sum_sofar = max_sum_upto_here ;
		}
		
		
	}
	printf("maximum subarray sum = %d\n" , max_sum_sofar);
	
	
}