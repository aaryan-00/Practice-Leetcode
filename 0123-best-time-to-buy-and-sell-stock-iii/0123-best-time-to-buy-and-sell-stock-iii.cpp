class Solution {
public:
    int memo(vector<int>& p,int ind,int buy,vector<vector<vector<int>>> &dp,int transactions)
    {
        if(ind==p.size() || transactions==0)
        {
            return 0;
        }
        if(dp[ind][buy][transactions]!=-1)
        {
            return dp[ind][buy][transactions];
        }
        int profit=0;
        if(buy==1)
        {
            profit=max(-p[ind]+memo(p,ind+1,0,dp,transactions),memo(p,ind+1,1,dp,transactions));
        }
        else
        {
            profit=max(p[ind]+memo(p,ind+1,1,dp,transactions-1),memo(p,ind+1,0,dp,transactions));
        }
        return dp[ind][buy][transactions]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return memo(prices,0,1,dp,2);
        
    }
};