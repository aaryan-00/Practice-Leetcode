class Solution {
public:
    int dp[51][51];
    int getAns(int n,int ind)
    {
        if(n==0) return 1;
        if(dp[n][ind]!=-1) return dp[n][ind];
        int sum=0;
        for(int i=ind;i<=5;i++)
        {
            sum+=getAns(n-1,i);
        }
        return dp[n][ind]=sum;
    }
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(n,1);
    }
};