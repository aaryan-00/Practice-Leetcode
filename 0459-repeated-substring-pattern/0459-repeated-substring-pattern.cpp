class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n-1;i>=1;i--)
        {
            string curr=s.substr(i)+s.substr(0,i);
            // cout<<curr<<endl;
            if(curr==s) return true;
        }
        return false;
    }
};