class Solution {
public:
    bool memo(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k=j;k>=0;k--)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //if equal
        if(s[i]==p[j])
        {
            return dp[i][j]=memo(s,p,i-1,j-1,dp);
        }
        //if ?
        if(p[j]=='?')
        {
            return dp[i][j]=memo(s,p,i-1,j-1,dp);
        }
        //if *
        else if(p[j]=='*')
        {
            bool zeroo=memo(s,p,i,j-1,dp);
            bool many=memo(s,p,i-1,j,dp);
            return dp[i][j]=zeroo||many;
        }
        else
        {
            return dp[i][j]=false;
        }


    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memo(s,p,n-1,m-1,dp);
    }
};