class Solution {
public:
    bool checkPalin(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int memo(int i,int j,string &s,vector<int> &dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int cost=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(checkPalin(s,i,k))
            {
                int curr=memo(k+1,j,s,dp)+1;
                cost=min(cost,curr);
            }   
        }
        return dp[i]=cost;
    }

    int memo2(int i,int j,string &s,vector<int> &dp)
    {
        if(i==j)
        {
            return 0;
        }
        if(checkPalin(s,i,j))
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int cost=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(checkPalin(s,i,k))
            {
                int curr=memo2(k+1,j,s,dp)+1;
                cost=min(cost,curr);
            }  
        }
        return dp[i]=cost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        // return memo(0,n,s,dp)-1;
        return memo2(0,n-1,s,dp);
    }
};