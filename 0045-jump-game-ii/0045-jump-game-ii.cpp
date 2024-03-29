class Solution {
public:
    int dp[10001];
    int getAns(vector<int> &nums,int ind)
    {
        if(ind==nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=1e6;
        for(int i=ind+1;i<=min((int)nums.size()-1,ind+nums[ind]);i++)
        {
            int curr=1+getAns(nums,i);
            ans=min(ans,curr);
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return getAns(nums,0);
        
    }
};