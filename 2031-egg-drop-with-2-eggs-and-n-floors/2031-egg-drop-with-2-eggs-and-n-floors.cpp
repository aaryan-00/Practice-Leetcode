class Solution {
public:
    int dp[1001][3];
    int getAns(int floor,int eggs)
    {
        if(floor<=1) return floor;
        if(eggs==1) return floor;
        if(dp[floor][eggs]!=-1) return dp[floor][eggs];
        int mini=INT_MAX;
        for(int i=1;i<=floor;i++)
        {
            mini=min(mini,1+max(getAns(i-1,eggs-1),getAns(floor-i,eggs)));
        }
        return dp[floor][eggs]=mini;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return getAns(n,2);
    }
};