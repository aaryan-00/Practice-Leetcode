class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int i=0;
        int ans=0;
        while(i<s.size())
        {
            if(s[i]==')' && st.size()>0)
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                st.push(s[i]);

            }
            i++;
        }
        ans+=st.size();
        return ans;
    }
};