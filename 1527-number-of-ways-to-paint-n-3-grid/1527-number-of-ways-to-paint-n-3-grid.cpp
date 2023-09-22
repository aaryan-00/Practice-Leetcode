class Solution {
public:
    const int m=1e9+7;
    int dp[5001][4][4][4];
    int getAns(int ind,int col1,int col2,int col3,int n)
    {
        if(ind==n) return 1;
        if(dp[ind][col1][col2][col3]!=-1) return dp[ind][col1][col2][col3];
        int ans=0;
        if(col1==0 && col2==0 && col3==0)
        {
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    for(int k=1;k<=3;k++)
                    {
                        if(i==j||j==k) continue;
                        ans=(ans+getAns(ind+1,i,j,k,n))%m;
                    }
                }
            }
        }
        else
        {
            for(int i=1;i<=3;i++)
            {
                if(i==col1) continue;
                for(int j=1;j<=3;j++)
                {
                    if(j==col2) continue;
                    for(int k=1;k<=3;k++)
                    {
                        if(k==col3) continue;
                        if(i==j||j==k) continue;
                        ans=(ans+getAns(ind+1,i,j,k,n))%m;

                    }
                }
            }
        }
        return dp[ind][col1][col2][col3]=ans%m;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(0,0,0,0,n);
    }
};