class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=(int)s[i-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans=0;
        for(auto i:s)
        {
            ans+=((int)i);
        }
        for(auto i:t)
        {
            ans+=((int)i);
        }
        return ans-2*dp[n][m];
    }
};