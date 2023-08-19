class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        vector<int> pre(s.size()),suf(s.size());
        set<char> temp;
        for(int i=0;i<s.size();i++)
        {
            temp.insert(s[i]);
            pre[i]=temp.size();
        }
        temp.clear();
        for(int i=s.size()-1;i>=0;i--)
        {
            temp.insert(s[i]);
            suf[i]=temp.size();
        }
        for(int i=0;i<s.size()-1;i++)
        {
            if(pre[i]==suf[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};