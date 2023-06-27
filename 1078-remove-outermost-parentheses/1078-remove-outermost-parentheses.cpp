class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<int> st;
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                if(cnt>1)
                {
                    ans+=s[i];
                }
            }
            else if(s[i]==')')
            {
                if(cnt==1)
                {
                    cnt--;
                }
                else
                {
                    ans+=s[i];
                    cnt--;
                }
                
            }
        }
        return ans;
    }
};