class Solution {
public:
    vector<int> preSum;
    int dp[1001][1001];
    int getAns(vector<int> &stones, int low,int high,int alice)
    {
        if(low==high) return 0;
        if(dp[low][high]!=-1) return dp[low][high];
        // if(alice)
        // {
            int diff=INT_MIN;
            diff=max(diff,preSum[high+1]-preSum[low+1]-getAns(stones,low+1,high,!alice));
            diff=max(diff,preSum[high]-preSum[low]-getAns(stones,low,high-1,!alice));
            return dp[low][high]= diff;
        // }
        // int diff=INT_MAX;
        //     diff=min(diff,preSum[high+1]-preSum[low+1]-getAns(stones,low+1,high,!alice));
        //     diff=min(diff,preSum[high]-preSum[low]-getAns(stones,low,high-1,!alice));
        // return diff;

    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        preSum.resize(n+1,0);
        for(int i=0;i<n;i++)
        {
            preSum[i+1]+=preSum[i]+stones[i];
        }
        // for(auto i:preSum)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        memset(dp,-1,sizeof(dp));
        return getAns(stones,0,n-1,1);

        // return 0;
    }
};