class Solution {
public:
    int memo(string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=memo(s,i+1,j-1,dp);
        }
        return dp[i][j]= 1 + min(memo(s,i,j-1,dp),memo(s,i+1,j,dp));

    }
    int memo2(string &s, string &t,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=1 + memo2(s,t,i-1,j-1,dp);
        }
        return dp[i][j]= max(memo2(s,t,i,j-1,dp),memo2(s,t,i-1,j,dp));

    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memo(s,0,n-1,dp);

        //ORR
        
        string t=s;
        reverse(t.begin(),t.end());
        int lcs = memo2(s,t,n-1,n-1,dp);
        return n-lcs;

    }
};