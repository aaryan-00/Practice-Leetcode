class Solution {
public:
    int recur(int ind,vector<int> &nums,int target,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target==0 && nums[0]==0)
            {
                return 2;
            }
            else if(target==0||target==nums[0])
            {
                return 1;
            }
            else return 0;
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        //not taken
        int ntkn=recur(ind-1,nums,target,dp);
        //taken
        int tkn=0;
        if(nums[ind]<=target)
        {
            tkn=recur(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]=tkn+ntkn;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int diff=sum-target;
        if(diff<0 || diff&1) return 0;
        diff=diff/2;
        vector<vector<int>> dp(n,vector<int>(diff+1,-1));
        return recur(n-1,nums,diff,dp);
    }
};