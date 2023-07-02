class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto i:t)
        {
            mp[i]++;
        }
        int cnt=t.size();
        int minPos=0,ans=INT_MAX,start=0;
        for(int end=0;end<s.size();end++)
        {
            if(mp[s[end]]>0) cnt--;
            mp[s[end]]--;
            while(cnt==0)
            {
                if(ans>end-start+1)
                {
                    ans=end-start+1;
                    minPos=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0) cnt++;
                start++;
            }
        }
        if(ans!=INT_MAX) return s.substr(minPos,ans);
        return "";
    }

    //using 128 size hash

    // string minWindow(string s, string t) {
    //     vector<int> mp(128,0);
    //     for(auto i:t)
    //     {
    //         mp[i]++;
    //     }
    //     int cnt=t.size();
    //     int minPos=0,ans=INT_MAX,start=0;
    //     for(int end=0;end<s.size();end++)
    //     {
    //         if(mp[s[end]]>0) cnt--;
    //         mp[s[end]]--;
    //         while(cnt==0)
    //         {
    //             if(ans>end-start+1)
    //             {
    //                 ans=end-start+1;
    //                 minPos=start;
    //             }
    //             mp[s[start]]++;
    //             if(mp[s[start]]>0) cnt++;
    //             start++;
    //         }
    //     }
    //     if(ans!=INT_MAX) return s.substr(minPos,ans);
    //     return "";
    // }
};