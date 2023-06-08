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
        int profit=0;
        if(buy==1)
        {
            // //bought
            // int buyy=-p[ind]+memo(p,ind+1,0,dp);
            // //not bought
            // int nbuyy=0+memo(p,ind+1,1,dp);
            // return dp[ind][buy]= max(buyy,nbuyy);
            profit=max(-p[ind]+memo(p,ind+1,0,dp),memo(p,ind+1,1,dp));

        }
        else
        {
            // //sold
            // int sold=p[ind]+memo(p,ind+1,1,dp);
            // //not sold
            // int nsold=0+memo(p,ind+1,0,dp);
            // return dp[ind][buy]= max(sold,nsold);
            profit=max(p[ind]+memo(p,ind+1,1,dp),memo(p,ind+1,0,dp));
        }
        return dp[ind][buy]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return memo(prices,0,1,dp);
        
        //tabulation
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=1;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy==1)
                {
                    profit=max(-prices[ind]+memo(prices,ind+1,0,dp),memo(prices,ind+1,1,dp));

                }
                else
                {
                    profit=max(prices[ind]+memo(prices,ind+1,1,dp),memo(prices,ind+1,0,dp));
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};