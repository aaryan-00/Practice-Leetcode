class Solution {
public:
int ans=0;
    void find_palindrome(string &s, int left,int right)
    {
        while(left>=0 && right<s.size())
        {
            if(s[left]!=s[right])
            {
                break;
            }
            left--,right++;
            ans++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++)
        {
            find_palindrome(s,i,i);
            find_palindrome(s,i,i+1);
        }
        return ans;
    }
};