class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(1,poured);
        for(int i=2;i<=query_row+1;i++)
        {
            vector<double> curr(i,0);
            for(int j=0;j<i-1;j++)
            {
                if(dp[j]>=1)
                {
                    curr[j]+=(dp[j]-1)/2.0;
                    curr[j+1]+=(dp[j]-1)/2.0;
                }
            }
            dp=curr;
        }

        return min(1.0,dp[query_glass]);
    }
};