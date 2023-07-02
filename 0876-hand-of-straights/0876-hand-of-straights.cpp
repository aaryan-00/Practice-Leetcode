class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto i:hand)
        {
            mp[i]++;
        }
        while(mp.size())
        {
            int curr=mp.begin()->first;
            for(int i=curr;i<curr+groupSize;i++)
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