class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long prev=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==prev) continue;
            int diff=nums[i]-prev-1;
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
                ans+=temp;
                prev=nums[i];
            }
        }
        if(k!=0)
        {
            long long curr=prev+k;
            long long temp=curr*(curr+1)/2 - prev*(prev+1)/2;
            ans+=temp;
        }

        return ans;
    }
};