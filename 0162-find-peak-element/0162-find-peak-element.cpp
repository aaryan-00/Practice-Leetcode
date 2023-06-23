class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<e)
        {
            int mid=s+e >>1;
            if(mid==0)
            { 
                if(nums[mid]>=nums[mid+1]) return mid;
                else return mid+1;
            }
            if(mid==n-1 )
            {
                if(nums[mid]>=nums[mid-1]) return mid;
                else return mid-1;
            }
            if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]) return mid;
            else if(nums[mid]<nums[mid-1])
            {
                e=mid-1;
            }
            else s=mid+1;
        }
        return s;
    }
};