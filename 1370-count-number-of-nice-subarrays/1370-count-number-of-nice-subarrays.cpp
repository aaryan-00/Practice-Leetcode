class Solution {
public:
    int atmostOdd(vector<int> &nums,int k)
    {
        int cnt=0;
        int start=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1) cnt++;
            while(cnt>k && start<i)
            {
                if(nums[start]&1) cnt--;
                start++;
            }
            if(cnt<=k) ans+=(i-start+1);

            // or

            // while(cnt>k && start<=i)
            // {
            //     if(nums[start]&1) cnt--;
            //     start++;
            // }
            // ans+=(i-start+1); //will work when start<=i;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostOdd(nums,k)-atmostOdd(nums,k-1);
    }
};