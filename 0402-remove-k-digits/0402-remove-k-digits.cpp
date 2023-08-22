class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty() && num[i]<st.top() && k>0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        string ans="";
        while(k--)
        {
            st.pop();
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        for(;i<ans.size();i++)
        {
            if(ans[i]!='0')break;
        }
        string temp=ans.substr(i);
        if(temp.size()==0) return "0";
        return temp;
    }
};