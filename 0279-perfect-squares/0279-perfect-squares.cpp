class Solution {
public:
    vector<int> dp;
    int getAns(int n,int sq,int sum)
    {
        if(sum==n) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=INT_MAX;
        for(int i=1;i<=sq;i++)
        {
            if(i*i<=n-sum)
            {
                ans=min(ans,1+getAns(n,sq,sum+i*i));
            }
            else 
            {
                break;
            }
        }
        return dp[sum]=ans;
    }
    int numSquares(int n) {
        int sq=sqrt(n);
        dp.resize(n,-1);
        return getAns(n,sq,0);
    }
};