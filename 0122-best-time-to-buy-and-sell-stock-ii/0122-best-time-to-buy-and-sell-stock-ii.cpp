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
            // int buyy=-p[ind]+memo(p,ind+1,0,dp);
            // int nbuyy=0+memo(p,ind+1,1,dp);
            // return dp[ind][buy]= max(buyy,nbuyy);
            profit=max(-p[ind]+memo(p,ind+1,0,dp),memo(p,ind+1,1,dp));

        }
        else
        {
            // int sold=p[ind]+memo(p,ind+1,1,dp);
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
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // dp[n][0]=dp[n][1]=0;
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         int profit=0;
        //         if(buy==1)
        //         {
        //             profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);

        //         }
        //         else
        //         {
        //             profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
        //         }
        //         dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];

        //space optimization
        // vector<int> next(2,0);
        // next[0]=next[1]=0;
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         int profit=0;
        //         if(buy==1)
        //         {
        //             profit=max(-prices[ind]+next[0],next[1]);

        //         }
        //         else
        //         {
        //             profit=max(prices[ind]+next[1],next[0]);
        //         }
        //         next[buy]=profit;
        //     }
        // }
        // return next[1];

        //easy loop
        int profit=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]-prices[i-1]>0)
            {
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;



    }
};