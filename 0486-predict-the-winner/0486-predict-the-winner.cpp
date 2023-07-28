class Solution {
public:
    
    // int getAns(vector<int> &nums,int st,int en,int turn)
    // {
    //     if(st>en)
    //     {
    //         return 0;
    //     }
    //     if(turn)
    //     {
    //         return max(nums[st]+getAns(nums,st+1,en,!turn),nums[en]+getAns(nums,st,en-1,!turn));
    //     }
    //     return min(-nums[st]+getAns(nums,st+1,en,!turn),-nums[en]+getAns(nums,st,en-1,!turn));

    // }
    // bool PredictTheWinner(vector<int>& nums) {
    //     int n=nums.size();
    //     return getAns(nums,0,n-1,1)>=0;
    // }
    vector<vector<int>> dp;
    int getAns(vector<int> &nums,int st,int en,int turn)
    {
        if(st>en)
        {
            return 0;
        }
        if(dp[st][en]!=-1) return dp[st][en];
        if(turn)
        {
            dp[st][en] = max(nums[st]+getAns(nums,st+1,en,!turn),nums[en]+getAns(nums,st,en-1,!turn));
        }
        else
        {
            dp[st][en] = min(-nums[st]+getAns(nums,st+1,en,!turn),-nums[en]+getAns(nums,st,en-1,!turn));
        }
        return dp[st][en];

    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return getAns(nums,0,n-1,1)>=0;
    }
};