class Solution {
public:
    int memo(int i,int j,vector<int>& arr,vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int steps=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int ans=memo(i,k-1,arr,dp)+memo(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j+1];
            steps=max(steps,ans);
        }
        return dp[i][j]=steps;
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return memo(1,n,nums,dp);
    }
};