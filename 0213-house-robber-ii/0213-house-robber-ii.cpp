class Solution {
public:
    vector<int> dp;
    // int getMaxi(vector<int> &nums,int ind,int n)
    // {
    //     if(ind>=n) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int take=nums[ind]+getMaxi(nums,ind+2,n);
    //     int ntake=getMaxi(nums,ind+1,n);
    //     dp[ind] = max(take,ntake);
    //     return dp[ind];
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     dp.assign(n,-1);
    //     int maxi1=getMaxi(nums,0,n-1);
    //     dp.assign(n,-1);
    //     int maxi2=getMaxi(nums,1,n);
    //     return max(maxi1,maxi2);
    // }

    int getMaxi(vector<int> &nums,int ind,int n)
    {
        int twoStepBack=0,oneStepBack=0;
        for (int i = ind; i < n; ++i) {
            int curr = max(oneStepBack, twoStepBack + nums[i]);
            twoStepBack = oneStepBack;
            oneStepBack = curr;
        }
        return oneStepBack;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(getMaxi(nums,0,n-1),getMaxi(nums,1,n));
    }
};