class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char,int> mp;
    //     int start=0,cnt=0,ans=0;
    //     for(int i=0;i<s.size();i++)
    //     {
    //         mp[s[i]]++;
    //         cnt++;
    //         if(mp.size()==cnt)
    //         {
    //             ans=max(ans,cnt);
    //         }
    //         while(mp.size()!=cnt)
    //         {
    //             if(mp[s[start]]==1)
    //             {
    //                 mp.erase(s[start]);
    //             }
    //             else
    //             {
    //                 mp[s[start]]--;
    //             }
    //             start++;
    //             cnt--;
    //         }
    //     }
    //     return ans;
    // }

    int lengthOfLongestSubstring(string s) {
      vector < int > mpp(256, -1);
      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};