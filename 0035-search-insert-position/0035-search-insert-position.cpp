class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};