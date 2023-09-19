class Solution {
public: 
    int dp[1001][3][3];
    const int m=1e9+7;
    int getAns(int i,int first,int second,int n)
    {
        if(i==n)
        {
            if(first+second==0) return 1;
            else return 0;
        }
        if(dp[i][first][second]!=-1) return dp[i][first][second];
        int ans=0;
        if(first+second==2)
        {
            return dp[i][first][second]=getAns(i+1,0,0,n);
        }
        else if(first+second==0)
        {
            long a=0,b=0,c=0,d=0;
            a=getAns(i+1,0,0,n);
            b=getAns(i+1,1,1,n);
            c=getAns(i+1,1,0,n);
            d=getAns(i+1,0,1,n);
            return dp[i][first][second]=(a+b+c+d)%m;
        }
        else if(first==1)
        {

            long a=getAns(i+1,1,1,n);
            long b=getAns(i+1,0,1,n);
            return dp[i][first][second]=(a+b)%m;
        }
        else if(second==1)
        {
            long a=getAns(i+1,1,1,n);
            long b=getAns(i+1,1,0,n);
            return dp[i][first][second]=(a+b)%m;
        }
        return 0;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(0,0,0,n);
    }
};