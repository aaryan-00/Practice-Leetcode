class Solution {
public:
    int dp[101][101];
    bool getAns(int i,int j,string &s1,string &s2,string &s3)
    {
        if(i==s1.size() && j==s2.size() && i+j==s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        bool ans=false;
        if(s3[k]==s1[i] && i<s1.size())
        {
            ans=ans||getAns(i+1,j,s1,s2,s3);
        }
        if(s3[k]==s2[j] && j<s2.size())
        {
            ans=ans||getAns(i,j+1,s1,s2,s3);
        }
        return dp[i][j]=ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return getAns(0,0,s1,s2,s3);
    }
};