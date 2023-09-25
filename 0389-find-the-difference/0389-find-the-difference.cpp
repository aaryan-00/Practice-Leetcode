class Solution {
public:
    char findTheDifference(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // int i=0;
        // while(i<s.size())
        // {
        //     if(s[i]!=t[i]) return t[i];
        //     i++;
        // }
        // return t[i];
        char ans=0;
        int i=0;
        while(i<t.size())
        {
            ans+=t[i];
            if(i<t.size()-1)ans-=s[i];
            i++;
        }
        return ans;
    }
};