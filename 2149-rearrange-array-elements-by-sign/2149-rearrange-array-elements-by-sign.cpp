class Solution {
public:
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> neg;
    //     vector<int> pos;
    //     for(auto &i:nums)
    //     {
    //         if(i<0) neg.push_back(i);
    //         else pos.push_back(i);
    //     }
    //     vector<int> ans;
    //     for(int i=0;i<neg.size();i++)
    //     {
    //         ans.push_back(pos[i]);
    //         ans.push_back(neg[i]);
    //     }
    //     return ans;
    // }

    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pos=0,neg=1;       
        for(auto &i:nums)
        {
            if(i<0) 
            {
                ans[neg]=i;
                neg+=2;
            }
            else 
            {
                ans[pos]=i;
                pos+=2;
            }
        }
        return ans;
    }
};