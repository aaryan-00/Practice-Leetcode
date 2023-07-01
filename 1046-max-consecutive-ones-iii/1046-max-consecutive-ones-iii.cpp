class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> pos;
        int ans=0;
        int cnt=0;
        int start=0;
        int iter=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                pos.push_back(i);
                cnt++;
            }
            // cout<<pos.size()<<" "<<cnt<<" ";
            if(cnt>k)
            {
                start=pos[iter]+1;
                iter++;
                cnt--;
            }
            ans=max(ans,i-start+1);
            // cout<<ans<<endl;
        }
        return ans;
    }
};