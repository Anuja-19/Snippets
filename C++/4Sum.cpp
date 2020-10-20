class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        set<vector<int>> hash;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++)
             {
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right) 
                {
                    int sum = nums[i] + nums[left] + nums[right] + nums[j];
                    if(sum == target && !hash.count({nums[i], nums[j], nums[left], nums[right]})) {
                        hash.insert({nums[i], nums[j], nums[left], nums[right]});
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if(target > sum) 
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};