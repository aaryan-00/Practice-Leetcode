class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int low=j+1,high=nums.size()-1;
                while(low<high)
                {
                    long sum=(long)nums[i]+(long)nums[j]+(long)nums[low]+(long)nums[high];
                    if(sum>target) high--;
                    else if(sum<target) low++;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++,high--;
                    }
                }
            }
        }
        return ans;
    }

    //     vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> ans;
    //     for(int k=0;k<nums.size();k++)
    //     {
    //         if(k>0 && nums[k]==nums[k-1])continue;
    //         for(int i=k+1;i<nums.size();i++)
    //         {
    //             if(i>k+1 && nums[i]==nums[i-1])continue;
    //             int low=i+1,high=nums.size()-1;
    //             while(low<high)
    //             {
    //                 long sum=nums[k];
    //                 sum+=nums[i];
    //                 sum+=nums[low];
    //                 sum+=nums[high];
    //                 // cout<<k<<" "<<i<<" "<<sum<<endl;
    //                 if(sum>target) high--;
    //                 else if(sum<target) low++;
    //                 else
    //                 {
    //                     ans.push_back({nums[k],nums[i],nums[low],nums[high]});
    //                     while(low<high && nums[low]==nums[low+1]) low++;
    //                     while(low<high && nums[high]==nums[high-1]) high--;
    //                     low++,high--;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};