class Solution {
public:
    bool recur(int i, vector<int> &arr,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(sum<0 || i==arr.size())
        {
            return false;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        //taken
        bool tkn=recur(i+1,arr,sum-arr[i],dp);
        //not taken
        bool ntkn=recur(i+1,arr,sum,dp);
        return dp[i][sum] = tkn||ntkn;

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum&1) return false;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return recur(0,nums,sum/2,dp);
    }
};