class Solution {
public:
    // int minOperations(vector<int>& nums, int x) {
    //     int n=nums.size();
    //     if(nums[0]>x and nums[n-1]>x) return -1;
    //     vector<int> presum(n+1,0);
    //     unordered_map<int,int> mp;
    //     mp[0]=0;
    //     for(int i=1;i<=n;i++)
    //     {
    //         presum[i]=presum[i-1]+nums[i-1];
    //         mp[presum[i]]=i;
    //     }
    //     if(presum[n]<x) return -1;
    //     vector<int> suff(n+1,0);
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         suff[i]=suff[i+1]+nums[i];
    //     }
    //     reverse(suff.begin(),suff.end());
    //     int ans=INT_MAX;
    //     for(int i=0;i<=n;i++)
    //     {
    //         if(suff[i]<=x && mp.find(x-suff[i])!=mp.end())
    //         {
    //             ans=min(ans,i+mp[x-suff[i]]);
    //         }
    //     }
    //     if(ans==INT_MAX) return -1;
    //     return ans;    
    // }

    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        if(nums[0]>x and nums[n-1]>x) return -1;
        int sum=0;
        for(auto &i:nums)
        {
            sum+=i;
        }
        sum-=x;
        if(sum<0) return -1;
        if(sum==0) return n;
        int s=0,e=0;  
        int curr=0; 
        int ans=INT_MIN; 
        while(e<n)
        {
            while(curr+nums[e]>sum && s<=e)
            {
                curr-=nums[s];
                s++;
            }
            curr+=nums[e];
            if(curr==sum) 
            {
                ans=max(ans,e-s+1);
            }
            e++; 
        }
        return n-ans;
    }
};