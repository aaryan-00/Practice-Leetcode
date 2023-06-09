class Solution {
public:
    int recur(vector<int> &nums,int i,int prev,vector<int> &dp)
    {
        if(i==nums.size())
        {
            return 0;
        }
        if(dp[prev+1]!=-1)
        {
            return dp[prev+1];
        }
        int tkn=0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            tkn = 1+recur(nums,i+1,i,dp);
        }
        int ntkn=recur(nums,i+1,prev,dp);
        return dp[prev+1]=max(tkn,ntkn);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1,-1);
        // return recur(nums,0,-1,dp);
        
        //tabulation
        // vector<int> dp(n+1,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int prev=i-1;prev>=-1;prev--)
        //     {
        //         int tkn=0;
        //         if(prev==-1 || nums[i]>nums[prev])
        //         {
        //             tkn = 1+dp[i+1];
        //         }
        //         int ntkn=dp[prev+1];
        //         dp[prev+1]=max(tkn,ntkn);
        //     }
        // }
        // return dp[0];

        vector<int> dp(n,1);
        
        for(int i=0; i<=n-1; i++)
        {
            for(int prev_index = 0; prev_index <=i-1; prev_index ++)
            {
                if(nums[prev_index]<nums[i] && 1+dp[prev_index]>dp[i] )
                {
                    dp[i] =1 + dp[prev_index];
                }
            }
        }
        int ans = -1;
        for(int i=0; i<=n-1; i++){
            if(dp[i]>ans)
            {
                ans=dp[i];
            }
        }
        return ans;

        //binary search
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for(int i=1;i<n;i++)
        // {
        //     if(temp.back()<nums[i])
        //     {
        //         temp.push_back(nums[i]);
        //     }
        //     else
        //     {
        //         int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        //         temp[ind]=nums[i];
        //     }
        // }
        // return temp.size();
    }
};