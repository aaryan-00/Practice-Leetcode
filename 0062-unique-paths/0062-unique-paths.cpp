class Solution {
public:
#define ll long long
    ll dp[105][105];
    ll paths(ll m,ll n)
    {
        if(m==1 && n==1)
        {
            return 1;
        }
        if(m<1 ||n<1)
        {
            return 0;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];    
        }
        ll left=paths(m-1,n);
        ll up=paths(m,n-1);
        return dp[m][n]=left+up;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return paths(m,n);
    }
};