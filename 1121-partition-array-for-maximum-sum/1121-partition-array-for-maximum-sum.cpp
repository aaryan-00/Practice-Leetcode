class Solution {
public:
    int n;
    vector<int> dp;
    int getAns(vector<int>& arr,int k,int ind)
    {
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int sum=0,maxi=0;
        int ans=0;
        for(int i=ind;i<min(ind+k,n);i++)
        {
            maxi=max(maxi,arr[i]);
            sum=(i-ind+1)*maxi+getAns(arr,k,i+1);
            ans=max(ans,sum);
        }
        return dp[ind]=ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.resize(n,-1);
        return getAns(arr,k,0);
    }
};