class Solution {
public:
    int longestValidParentheses(string s) {
        int n =s.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(s[st.top()]=='(') 
                {
                    st.pop();
                }
                else st.push(i);
            }
        }
        // cout<<st.size()<<endl;
        if(st.empty()) return n;
        int end=n;
        while(!st.empty())
        {
            int start=st.top();
            st.pop();
            ans=max(ans,end-start-1);
            end=start;
        }
        ans=max(ans,end);
        return ans;
    }
};