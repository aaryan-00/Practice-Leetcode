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
        if(buy==1)
        {
            return dp[ind][buy][transactions]=max(-p[ind]+memo(p,ind+1,0,dp,transactions),memo(p,ind+1,1,dp,transactions));
        }
        else
        {
            return dp[ind][buy][transactions]=max(p[ind]+memo(p,ind+1,1,dp,transactions-1),memo(p,ind+1,0,dp,transactions));
        }

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memo(prices,0,1,dp,k);

        // space optimisation(tabulation)
        // vector<vector<int>> next(2,vector<int>(k+1,0));
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         for(int cap=1;cap<=k;cap++)
        //         {
        //             if(buy==1)
        //             {
        //                 next[buy][cap]=max(-prices[ind]+next[0][cap],next[1][cap]);
        //             }
        //             else
        //             {
        //                 next[buy][cap]=max(prices[ind]+next[1][cap-1],next[0][cap]);
        //             }
        //         }
        //     }
        // }
        // return next[1][k];
    }
};