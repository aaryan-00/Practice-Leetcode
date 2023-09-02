class Solution {
public:
    unordered_set<string> ss;
    vector<int> dp;
    int getAns(string &s,int ind)
    {
        if(ind==s.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MAX;
        for(int i=ind+1;i<=s.size();i++)
        {
            string temp=s.substr(ind,i-ind);
            // cout<<temp<<endl;
            if(ss.count(temp))
            {
               ans=min(ans,getAns(s,i));
            }
            else
            {
                ans=min(ans,i-ind+getAns(s,i));
            }
        }
        return dp[ind]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto &i:dictionary)
        {
            ss.insert(i);
        }
        dp.resize(s.size(),-1);
        return getAns(s,0);
    }
};