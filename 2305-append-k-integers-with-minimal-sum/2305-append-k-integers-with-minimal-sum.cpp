class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(auto i:nums)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        long long prev=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==prev) continue;
            int diff=nums[i]-prev-1;
            cout<<diff<<endl;
            if(diff==0) 
            {
                prev=nums[i];
                continue;
            }
            if(diff>=k)
            {
                long long curr=prev+k;
                long long temp=curr*(curr+1)/2 - prev*(prev+1)/2;
                k=0;
                ans+=temp;
                break;
            }
            else
            {
                long long curr=nums[i]-1;
                long long temp=curr*(curr+1)/2 - prev*(prev+1)/2;
                k-=diff;
                // cout<<temp<<endl;
                ans+=temp;
                prev=nums[i];
            }
        }
        // cout<<ans<<endl;
        if(k!=0)
        {
            long long curr=prev+k;
            // cout<<curr<<endl;
            long long temp=curr*(curr+1)/2 - prev*(prev+1)/2;
            // cout<<temp<<endl;
            ans+=temp;
        }

        return ans;
    }
};