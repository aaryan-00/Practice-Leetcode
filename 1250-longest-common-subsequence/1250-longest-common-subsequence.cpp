class Solution {
public:
    #define ll long long
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    int Memo(string &s,string &t,int i,int j,vvi &dp)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]= 1 + Memo(s,t,i-1,j-1,dp);
        }
        return dp[i][j]= max(Memo(s,t,i,j-1,dp),Memo(s,t,i-1,j,dp));

    }
    int longestCommonSubsequence(string s, string t) {
        ll n=s.size(),m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return Memo(s,t,n-1,m-1,dp);

        //Tabulation
        // vvi dp(n+1,vi(m+1,-1));
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         if(i==0||j==0)
        //         {
        //             dp[i][j]=0;
        //         }
        //         else
        //         {
        //             if(s[i-1]==t[j-1])
        //             {
        //                 dp[i][j]=1+dp[i-1][j-1];
        //             }
        //             else
        //             {
        //                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //             }
        //         }
        //     }
        // }
        // return dp[n][m];
    }
};