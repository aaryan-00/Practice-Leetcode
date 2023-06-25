class Solution {
public:
    bool isPossible(vector<int> &a, int n,int m,int mid)
    {
        int cnt=0;
        long temp=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>mid) return false;
            temp+=a[i];
            if(temp>mid)
            {
                cnt++;
                temp=a[i];
            }
        }
        if(temp>0) cnt++;
        // cout<<cnt<<endl;
        
        return cnt<=m;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        // cout<<sum<<endl;
        int s=*max_element(nums.begin(),nums.end()),e=sum;
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            // cout<<mid<<" ";
            if(isPossible(nums,n,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};