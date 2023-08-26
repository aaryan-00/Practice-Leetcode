class Solution {
public:
    int ans=0;
    bool palin(string &s)
    {
        int l=0,h=s.size()-1;
        while(l<h)
        {
            if(s[l]!=s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    void getAns(string& s, int idx, string &s1, string &s2) {
        if (idx == s.size()) {
            if(palin(s1) && palin(s2))
            {
                ans=max(ans,(int)s1.size()*(int)s2.size());
            }
            return;
        }
        s1.push_back(s[idx]);
        getAns(s, idx + 1, s1, s2);
        s1.pop_back();
        s2.push_back(s[idx]);
        getAns(s, idx + 1, s1, s2);
        s2.pop_back();
        getAns(s, idx + 1, s1, s2);
}
    int maxProduct(string s) {
        string s1="",s2="";
        getAns(s,0,s1,s2);
        return ans;
    }
};