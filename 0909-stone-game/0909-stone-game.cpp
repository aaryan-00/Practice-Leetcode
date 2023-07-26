class Solution {
public:
    // turn==1 for alice and 0 for bob
    bool getWinner(vector<int> &piles,int turn,int start,int end,vector<vector<int>> &dp)
    {
        if(start>end) return 0;
        if(start==end) return piles[start];
        if(dp[start][end]!=-1) return dp[start][end];
            
        if(turn)
        {
            dp[start][end]=max(piles[start]+getWinner(piles,!turn,start+1,end,dp),piles[end]+getWinner(piles,!turn,start,end-1,dp));
        }
        else
        {
            dp[start][end]=min(-piles[start]+getWinner(piles,!turn,start+1,end,dp),-piles[end]+getWinner(piles,!turn,start,end-1,dp));
        } 
        return dp[start][end];
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return getWinner(piles,1,0,piles.size()-1,dp)>0;
    }
};