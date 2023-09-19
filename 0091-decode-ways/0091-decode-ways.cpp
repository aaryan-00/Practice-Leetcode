class Solution {
public:
    int dp[101][28];
    int getAns(int i,int prev,string &s)
    {
        if(i==s.size())
        {
            if(prev==-1) return 1;
            return 0;
        }
        if(s[i]=='0' && prev==-1) return 0;
        if(prev==2 && s[i]>'6') return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int ans=0;
        if(prev==-1)
        {
            int curr=s[i]-'0';
            ans+=getAns(i+1,-1,s);
            if(curr<=2 && curr>0)
            {
                ans+=getAns(i+1,curr,s);
            }   
        }
        else
        {
            int curr=s[i]-'0';
            ans+=getAns(i+1,-1,s);

        }
        return dp[i][prev+1]=ans;
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        memset(dp,-1,sizeof(dp));
        return getAns(0,-1,s);
    }
};