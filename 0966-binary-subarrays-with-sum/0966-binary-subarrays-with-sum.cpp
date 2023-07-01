class Solution {
public:
    int atmostSum(vector<int> &nums,int goal)
    {
        int sum=0;
        int start=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            // while(sum>goal && start<i)
            // {
            //     sum-=nums[start];
            //     start++;
            // }
            // if(sum<=goal) ans+=(i-start+1);

            // or
            while(sum>goal && start<=i)
            {
                sum-=nums[start];
                start++;
            }
            ans+=(i-start+1);
        }
        // cout<<ans<<endl;
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSum(nums,goal)-atmostSum(nums,goal-1);
    }
};