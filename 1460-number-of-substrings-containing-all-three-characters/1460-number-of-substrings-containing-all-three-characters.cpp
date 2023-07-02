class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int n=s.size();
        int start=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while(mp['a'] && mp['b'] && mp['c'])
            {
                ans+=n-i;
                mp[s[start]]--;
                start++;
            }
        }
        return ans;
    }


    // int numberOfSubstrings(string s) {
    //     int ans=0;
    //     int n=s.size();
    //     int start=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         vector<int> mp(3,0);
    //         mp[s[i]-'a']++;
    //         int j=i+1;
    //         while(j<n && (mp[0]<1 || mp[1]<1 || mp[2]<1))
    //         {
    //             mp[s[j]-'a']++;
    //             j++;
    //         }
    //         if(mp.size()==3) ans+=(n-j+1);
    //     }
    //     return ans;
    // }
};