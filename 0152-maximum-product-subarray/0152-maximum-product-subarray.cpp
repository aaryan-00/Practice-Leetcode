class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int currMin=1,currMax=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                currMin=1,currMax=1;
            }
            else if(nums[i]>0)
            {
                currMax=max(nums[i],nums[i]*currMax);
                currMin=min(nums[i],nums[i]*currMin);
                ans=max(ans,currMax);
            }
            else
            {
                // cout<<currMax<<" "<<currMin<<endl;
                int temp=currMax;
                currMax=max(nums[i],nums[i]*currMin);
                currMin=min(nums[i],nums[i]*temp);
                ans=max(ans,currMax);
            }
        }
        return ans;
    }
};