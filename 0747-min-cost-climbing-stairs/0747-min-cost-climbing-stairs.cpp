class Solution {
public:
    int recur(int i,vector<int> &cost,vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(recur(i-1,cost,dp),recur(i-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);
        return recur(n,cost,dp);
    }
};