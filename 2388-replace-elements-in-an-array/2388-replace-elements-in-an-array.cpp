class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(auto &i:operations)
        {
            int a=i[0],b=i[1];
            int pos=mp[a];
            mp.erase(a);
            nums[pos]=b;
            mp[b]=pos;
        }
        return nums;
    }
};