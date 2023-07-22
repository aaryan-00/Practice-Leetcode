class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int cnt0=0,cnt1=0,cnt2=0;
    //     for(auto &i:nums)
    //     {
    //         if(i==0) cnt0++;
    //         else if(i==1) cnt1++;
    //         else cnt2++;
    //     }
    //     for(int i=0;i<cnt0;i++)nums[i]=0;
    //     for(int i=cnt0;i<cnt0+cnt1;i++)nums[i]=1;
    //     for(int i=cnt0+cnt1;i<nums.size();i++)nums[i]=2;
    // }

// a variation of the popular Dutch National flag algorithm. 
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++,mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};