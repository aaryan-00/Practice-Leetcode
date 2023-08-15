class Solution {
public:
    vector<int> dp;
    int getCombi(vector<int>& nums, int target,int sum)
    {
        if(sum==target) return 1;
        if(sum>target) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=getCombi(nums,target,sum+nums[i]);
        }
        return dp[sum]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target,-1);
        return getCombi(nums,target,0);
    }
};