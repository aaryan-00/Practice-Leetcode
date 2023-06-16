class Solution {
public:
    int recur(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=max(nums[i]+recur(i-2,nums,dp),recur(i-1,nums,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=2e4+1;
        vector<int> hash(n,0);
        for(auto i:nums)
        {
            cout<<i<<endl;
            hash[i]+=i;
        }
        vector<int> dp(n,-1);
        return recur(n-1,hash,dp);
    }
};