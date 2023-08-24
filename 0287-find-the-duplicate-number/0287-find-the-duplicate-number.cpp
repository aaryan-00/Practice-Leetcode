class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
            else
            {
                i++;
            }
        }
        int ans;
        for (i = 0; i < n; ++i)
        {   
            if (nums[i] != (i+1))
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};