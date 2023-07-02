class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k>nums.size() || nums.size()%k) return false;
        map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        while(mp.size())
        {
            int curr=mp.begin()->first;
            for(int i=curr;i<curr+k;i++)
            {
                if(mp[i]==0) return false;
                else
                {
                    mp[i]--;
                    if(mp[i]==0)
                    {
                        mp.erase(i);
                    }
                }
            }
        }
        return true;
    }
};