class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        // while(l<=r)
        while(l<r)
        {
            int mid = (l+r)>>1;
            // cout<<mid<<endl;
            // if(nums[l]<=nums[mid])
            // {
            //     if(nums[mid]<=nums[r]) return nums[l];
            //     else l=mid+1;
            // }
            // else
            // {
            //     if(nums[mid]<=nums[r]) r=mid;
            //     else l=mid+1;
            // }
            if(nums[mid]>=nums[r])
            {
                // if(nums[mid]<=nums[r]) return nums[l];
                l=mid+1;
            }
            else
            {
                r=mid;
                // else l=mid+1;
            }


        }
        return nums[l];
    }
};