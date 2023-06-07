class Solution {
public:
    int memo(string &s, string &t,int i,int j,vector<vector<int>> &dp)
    {
        if(j<0)
        {
            return i+1;
        }
        if(i<0)
        {
            return j+1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=memo(s,t,i-1,j-1,dp);
        }
        int insert=memo(s,t,i,j-1,dp);
        int deletee=memo(s,t,i-1,j,dp);
        int replace=memo(s,t,i-1,j-1,dp);
        return dp[i][j]=1+min(insert,min(deletee,replace));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return memo(word1,word2,n-1,m-1,dp);
        
        //Tabulation
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        } 
        return dp[n][m];
    }
};