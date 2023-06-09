class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        // int maxi=1;
        // int maxInd=0;
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=i-1;j>=0;j--)
            {
                if((nums[i]%nums[j]==0) && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                    // if(maxi<dp[i])
                    // {
                    //     maxi=dp[i];
                    //     maxInd=i;
                    // }
                }
            }
        }
        int maxi=-1;
        int maxInd=-1;

        for(int i=0; i<=n-1; i++){
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxInd]);
        while(hash[maxInd]!=maxInd)
        {
            maxInd=hash[maxInd];
            ans.push_back(nums[maxInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};