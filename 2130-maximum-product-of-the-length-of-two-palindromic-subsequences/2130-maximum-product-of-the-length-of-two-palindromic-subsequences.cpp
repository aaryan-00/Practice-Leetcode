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
    void generateDisjointSubsequences(string& s, int idx, string s1, string s2) {
        if (idx == s.size()) {
            if(palin(s1) && palin(s2))
            {
                ans=max(ans,(int)s1.size()*(int)s2.size());
            }
            return;
        }
        generateDisjointSubsequences(s, idx + 1, s1 + s[idx], s2);
        generateDisjointSubsequences(s, idx + 1, s1, s2 + s[idx]);
        generateDisjointSubsequences(s, idx + 1, s1, s2);
}
    int maxProduct(string s) {
        generateDisjointSubsequences(s,0,"","");
    return ans;
    }
};