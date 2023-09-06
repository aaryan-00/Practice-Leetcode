class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> v(nums.begin(), nums.end());
        long long ans=0;
        long long n=v.size();
        if(n==1)
        {
            ans=v[0];
        }
        for(long long i=n-1;i>=1;i--){
            if(v[i-1]<=v[i])
            {
                v[i-1]=v[i-1]+v[i];    
            }
            if(v[i-1]>ans)
            {
                ans=v[i-1];
            }
           
        }
        return ans;
    }
};