class Solution {
public:
    bool isPossible(vector<int> &nums,int mid,int k)
    {
        int cnt=0;
        for(auto i:nums)
        {
            cnt+=(i+mid-1)/mid;
        }
        cout<<cnt<<endl;
        return cnt<=k;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int maxi= *max_element(nums.begin(),nums.end());
        int mini= *min_element(nums.begin(),nums.end());
        int lo=1,hi=maxi;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+hi>>1;
            cout<<mid<<" ";
            if(isPossible(nums,mid,th))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};