class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;i++)
        {
            preSum[i+1]=preSum[i]+cardPoints[i];
        }
        // for(auto i:preSum)
        // {
        //     cout<<i<<" ";
        // }
        int ans=0;
        for(int i=0;i<=k;i++)
        {
            int curr=preSum[i]+preSum[n]-preSum[n-(k-i)];
            // cout<<curr<<endl;
            ans=max(ans,curr);
        }
        // cout<<endl;
        return ans;
    }
};