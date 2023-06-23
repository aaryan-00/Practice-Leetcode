class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<e)
        {
            int mid=s+e >>1;
            if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid==n-1 && nums[mid]!=nums[mid-1]) return nums[mid];
            if(nums[mid]==nums[mid-1])
            {
                int len=mid-s+1;
                if(len&1) e=mid;
                else s=mid+1;
            }
            else if(nums[mid]==nums[mid+1])
            {
                int len=e-mid+1;
                if(len&1) s=mid;
                else e=mid-1;
            }
            else return nums[mid];
        }
        return nums[s];

    }
};