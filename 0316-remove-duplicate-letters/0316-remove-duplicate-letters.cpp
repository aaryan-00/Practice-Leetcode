class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char,int> mp;
        for(auto &i:s)
        {
            mp[i]++;
        }
        unordered_set<char> vis;
        stack<char> st;
        st.push(s[0]);
        vis.insert(s[0]);
        mp[s[0]]--;
        for(int i=1;i<s.size();i++)
        {
            char curr=s[i];
            while(!st.empty() && st.top()>curr && mp[st.top()]>0 && vis.count(curr)==0)
            {
                // mp[st.top()]--;
                vis.erase(st.top());
                st.pop();

            }
            if(vis.count(curr)==0)
            {
                st.push(curr);
                vis.insert(curr);
            }
            mp[curr]--;
        }
        // cout<<st.size()<<endl;
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;


        
    }
};