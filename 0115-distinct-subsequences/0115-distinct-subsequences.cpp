class Solution {
public:
    int Memo(string &s,string &t,int i,int j,vector<vector<int>> &dp)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // if(s[i]==t[j])
        // {
        //     return dp[i][j]=Memo(s,t,i-1,j-1,dp)+Memo(s,t,i-1,j,dp);   
        // }
        // else
        // {
        //     return dp[i][j]= Memo(s,t,i-1,j,dp);
        // }

        //orrr
        
        int ans=0;
        if(s[i]==t[j])
        {
            ans+=Memo(s,t,i-1,j-1,dp);
            ans+=Memo(s,t,i-1,j,dp);   
        }
        else
        {
            ans+=Memo(s,t,i-1,j,dp); 
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return Memo(s,t,n-1,m-1,dp);
    }
};