class Solution {
public:
    vector<int> preSum;
    int dp[1001][1001];
    // int getAns(vector<int> &stones, int low,int high,int alice)
    // {
    //     if(low==high) return 0;
    //     if(dp[low][high]!=-1) return dp[low][high];
    //         int diff=INT_MIN;
    //         diff=max(diff,preSum[high+1]-preSum[low+1]-getAns(stones,low+1,high,!alice));
    //         diff=max(diff,preSum[high]-preSum[low]-getAns(stones,low,high-1,!alice));
    //         return dp[low][high]= diff;
    // }
    
    int getAns(vector<int> &stones, int low,int high,int alice){
        if(low==high) return 0;
        if(dp[low][high]!=-1) return dp[low][high];
        
        if(alice){//maximize Alice's gain
            int left = preSum[high+1]-preSum[low+1] + getAns(stones, low + 1, high, !alice);
            int right = preSum[high]-preSum[low] + getAns(stones, low, high - 1, !alice);
            return dp[low][high] = max(left, right);
        }
         // minimize Bob's gain
        int left = getAns(stones, low + 1, high, !alice) - (preSum[high+1]-preSum[low+1]);
        int right = getAns(stones, low, high - 1, !alice) - (preSum[high]-preSum[low]);
        return dp[low][high] = min(left, right);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        preSum.resize(n+1,0);
        for(int i=0;i<n;i++)
        {
            preSum[i+1]=preSum[i]+stones[i];
        }
        memset(dp,-1,sizeof(dp));
        return getAns(stones,0,n-1,1);
    }
};