class Solution {
public:
    int memo(vector<int>& p,int ind,int buy,vector<vector<int>> &dp,int fee)
    {
        if(ind>=p.size())
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        int profit=0;
        if(buy==1)
        {
            profit=max(-p[ind]+memo(p,ind+1,0,dp,fee),memo(p,ind+1,1,dp,fee));

        }
        else
        {
            profit=max(p[ind]-fee+memo(p,ind+1,1,dp,fee),memo(p,ind+1,0,dp,fee));
        }
        return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return memo(prices,0,1,dp,fee);
    }
};