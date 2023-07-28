class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int alll=1;
        for(auto &i:nums)
        {
            if(i!=0)
            {
                alll*=i;
            }
            else
            {
                zero++;
            }
        }
        vector<int> ans;
        for(auto &i:nums)
        {
            if(i==0)
            {
                if(zero>1) ans.push_back(0);
                else ans.push_back(alll);
            }
            else
            {
                if(zero>0) ans.push_back(0);
                else ans.push_back(alll/i);
            }
        }
        return ans;
    }
};