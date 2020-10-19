// Program to find max subarray sum using kandanes algorithm.
#include <iostream>
#include <vector>
using namespace std;
int kandane(vector<int>& nums);
int main()
{
	// getting the length of arr followed by arr elements.
	int n;
	cin>>n;
	vector<int>& nums
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	int max_sum_subarray = kandane(nums);
	cout<<"max_sum_subarray = " << max_sum_subarray ; 	
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int local_max = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if((local_max + nums[i])> nums[i]) 
                local_max+=nums[i];
            else
                local_max = nums[i];
            
            if(local_max>max) max = local_max;
        }
        
        
        return max;
        
    }
};
