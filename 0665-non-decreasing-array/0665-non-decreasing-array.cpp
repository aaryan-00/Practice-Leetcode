class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0,maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            // if(pre[i]>=pre[i+1])cnt++;
            if(nums[i]<maxi) cnt++;
            else
            {
                maxi=nums[i];
            }
            // if(cnt>1) return false;
        }
        int mini=nums[nums.size()-1],cnt2=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            // if(pre[i]>=pre[i+1])cnt++;
            if(nums[i]>mini) cnt2++;
            else
            {
                mini=nums[i];
            }
            // if(cnt>1) return false;
        }
        // cout<<cnt<<endl;
        return cnt<=1||cnt2<=1;
    }

};