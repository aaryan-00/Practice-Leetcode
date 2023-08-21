class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;i--)
        {
            if(n%i==0)
            {
                string curr=s.substr(i)+s.substr(0,i);
                if(curr==s) return true;
            }
        }
        return false;
    }
};