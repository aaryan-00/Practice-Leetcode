class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int> &nums,int ind,int p)
    {
        if(p==0) return 0;
        if(ind>=nums.size()-1) return 1e9;
        if(dp[ind][p]!=-1) return dp[ind][p];
        int take=max(abs(nums[ind]-nums[ind+1]),dfs(nums,ind+2,p-1));
        int nottake=dfs(nums,ind+1,p);
        return dp[ind][p]=min(take,nottake);
    }

    bool check(int mid,vector<int>&nums,int p)
    {
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // dp.resize(nums.size(),vector<int>(p+1,-1));
        // return dfs(nums,0,p);
//MLE in last 5 test cases
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+high >> 1;
            if(check(mid,nums,p))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;
    }
};