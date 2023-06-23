class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        int a=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]==target) a=mid;
            if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        if(a==-1) return {-1,-1};
        s=0,e=n-1;
        int b=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            if(nums[mid]==target) b=mid;
            if(nums[mid]<=target) s=mid+1;
            else e=mid-1;
        }
        return {a,b};

        
        
    }
};