class Solution {
public:
    int m=1e9+7;
    long long getAns(int n,int goal,int k,vector<vector<int>> &dp)
    {
        if(n==0 && goal==0)
        {
            return 1;
        }
        if(n==0 || goal==0)
        {
            return 0;
        }
        if(dp[n][goal]!=-1) return dp[n][goal];
        //newSong
        long long pick=getAns(n-1,goal-1,k,dp)*n;
        // old song
        long long notpick=getAns(n,goal-1,k,dp)*max(0,n-k);
        return dp[n][goal]=(pick+notpick)%m;

    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        return getAns(n,goal,k,dp);
    }
};