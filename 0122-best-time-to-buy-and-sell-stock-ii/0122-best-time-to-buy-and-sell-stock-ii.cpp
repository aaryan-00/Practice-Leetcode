class Solution {
public:
    int memo(vector<int>& p,int ind,int buy,vector<vector<int>> &dp)
    {
        if(ind==p.size())
        {
            return 0;
        }
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        }
        if(buy==1)
        {
            //bought
            int buyy=-p[ind]+memo(p,ind+1,0,dp);
            //not bought
            int nbuyy=0+memo(p,ind+1,1,dp);
            return dp[ind][buy]= max(buyy,nbuyy);
        }
        else
        {
            //sold
            int sold=p[ind]+memo(p,ind+1,1,dp);
            //not sold
            int nsold=0+memo(p,ind+1,0,dp);
            return dp[ind][buy]= max(sold,nsold);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return memo(prices,0,1,dp);
    }
};