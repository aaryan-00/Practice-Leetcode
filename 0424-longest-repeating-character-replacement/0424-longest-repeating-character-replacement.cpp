class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
        int start=0,maxFreq=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            int curr=s[i]-'A';
            mp[curr]++;
            maxFreq=max(maxFreq,mp[curr]);
            while(i-start+1 - maxFreq>k)
            {
                mp[s[start]-'A']--;
                start++;
                cout<<maxFreq<<endl;
                maxFreq=0;
                for(int i=0;i<26;i++)
                {
                    maxFreq=max(maxFreq,mp[i]);
                }
            }
            ans=max(ans,i-start+1);

        }
        return ans;
    }
};