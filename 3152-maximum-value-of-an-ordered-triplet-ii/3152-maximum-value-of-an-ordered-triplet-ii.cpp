class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=INT_MIN;
        vector<int> maxi(n),mini(n),rev_maxi(n);
        maxi[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        // mini[n-1]=nums[n-1];
        rev_maxi[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            // mini[i]=min(mini[i+1],nums[i]);
            rev_maxi[i]=max(rev_maxi[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++)
        {
            ans=max((maxi[i-1]-nums[i])*(long long)rev_maxi[i+1],ans);
        }
        // cout<<ans<<endl;
        if(ans<0) ans=0;
        return ans;
    }
};