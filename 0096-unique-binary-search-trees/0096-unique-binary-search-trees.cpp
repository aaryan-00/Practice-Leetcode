class Solution {
public:
    int dp[20];
    int getCount(int i)
    {
        if(i==0||i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        int cnt=0;
        for(int curr=0;curr<i;curr++)
        {
            cnt+=getCount(curr)*getCount(i-curr-1);
        }
        // cout<<cnt<<endl;
        return dp[i]=cnt;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return getCount(n);
    }
};