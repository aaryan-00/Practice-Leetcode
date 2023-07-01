class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int start=0,cnt=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            cnt++;
            if(mp.size()==cnt)
            {
                ans=max(ans,cnt);
            }
            while(mp.size()!=cnt)
            {
                if(mp[s[start]]==1)
                {
                    mp.erase(s[start]);
                }
                else
                {
                    mp[s[start]]--;
                }
                start++;
                cnt--;
            }
        }
        return ans;
    }
};