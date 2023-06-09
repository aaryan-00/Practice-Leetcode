class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
                if(nums[prev_index]<nums[i]){
                    if(dp[prev_index]+1>dp[i])
                    {
                        dp[i] =1 + dp[prev_index];
                        cnt[i]=cnt[prev_index];
                    }
                    else if(dp[prev_index]+1==dp[i])
                    {
                        cnt[i]+=cnt[prev_index];
                    }
                } 
                maxi = max(maxi,dp[i]);      
            }   
        }
        int ans =0;
        for(int i=0; i<=n-1; i++){
            if(dp[i]==maxi) 
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};