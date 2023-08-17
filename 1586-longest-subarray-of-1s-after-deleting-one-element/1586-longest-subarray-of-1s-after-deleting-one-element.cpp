class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        // for(auto i:pre)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        int temp=0;
        int ans=0;
        int zero=0;
        int cnt=0;
        bool f=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                temp++;
                ans=max(ans,temp);
            }
            else
            {
                f=true;
                cnt++;
                if(cnt==2)
                {
                    temp=pre[i]-pre[zero];
                    // pre[zero]=0;
                    cnt=1;
                }
                zero=i;
            }
            
            // cout<<ans<<" "<<temp<<endl;
        }
        if(!f)ans--;
        // ans=max(ans,temp);
        return ans;
    }
};