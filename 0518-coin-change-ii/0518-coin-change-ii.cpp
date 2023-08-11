class Solution {
public:
    int find(int ind,int amount,vector<int>& coins,vector<vector<int>> &dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(ind<0||amount<0)
        {
            return 0;
        }
        if(dp[ind][amount]!=-1)
        {
            return dp[ind][amount];
        }
        //nottaken;
        int ntk=find(ind-1,amount,coins,dp);
        //taken;
        int tk=find(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=tk+ntk;

    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= find(n-1,amount,coins,dp);
        return ans;
    }
};