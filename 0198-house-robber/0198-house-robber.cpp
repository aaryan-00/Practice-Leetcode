class Solution {
public:
    int recur(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=max(nums[i]+recur(i-2,nums,dp),recur(i-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(n-1,nums,dp);
    }
};