class Solution {
public:
    int dp[100001];
    int getAns(int n)
    {
        // cout<<n<<alice<<endl;
        if(n==0) 
        {
            return false;
        }
        if(dp[n]!=-1) return dp[n];
        bool ans=false;
        for(int i=1;i*i<=n;i++)
        {
            ans=ans || !getAns(n-i*i);
        }
        return dp[n]=ans;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(n);
    }
};