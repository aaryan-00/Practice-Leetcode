class Solution {
public:
    int recur(vector<int> &nums,int i,int prev,vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int tkn=0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            tkn = 1+recur(nums,i+1,i,dp);
        }
        int ntkn=recur(nums,i+1,prev,dp);
        return dp[i][prev+1]=max(tkn,ntkn);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recur(nums,0,-1,dp);
    }
};