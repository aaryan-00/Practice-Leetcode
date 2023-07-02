class Solution {
public:
    //preFix sum
    // int maxScore(vector<int>& cardPoints, int k) {
    //     int n=cardPoints.size();
    //     vector<int> preSum(n+1,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         preSum[i+1]=preSum[i]+cardPoints[i];
    //     }
    //     int ans=0;
    //     for(int i=0;i<=k;i++)
    //     {
    //         int curr=preSum[i]+preSum[n]-preSum[n-(k-i)];
    //         ans=max(ans,curr);
    //     }
    //     return ans;
    // }

    //sliding window
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        // cout<<sum<<endl;
        int ans=sum;
        for(int i=k-1;i>=0;i--)
        {
            sum-=cardPoints[i];
            sum+=cardPoints[n-k+i];
            // cout<<sum<<endl;
            ans=max(ans,sum);
        }
        return ans;
    }
};