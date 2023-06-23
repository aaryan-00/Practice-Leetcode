class Solution {
public:
    bool search(vector<int>& nums, int target) {
        vector<int> num;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1]) num.push_back(nums[i]);
        }
        num.push_back(nums[nums.size()-1]);
        int n=num.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            // cout<<mid<<endl;
            if(num[mid]==target) return true;
            if(num[l]<=num[mid])
            {
                if(num[l]<=target && target<num[mid]) r=mid-1;
                else l=mid+1;
                cout<<l<<" "<<r<<endl;
            }
            else
            {
                if(num[mid]<target && target<=num[r]) l=mid+1;
                else r=mid-1;
            }
        }
        // cout<<n<<endl;
        return false;
    }
};