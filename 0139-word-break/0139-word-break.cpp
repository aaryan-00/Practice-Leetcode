class Solution {
public:
    unordered_set<string> ss;
    int dp[301];
    bool getAns(string &s,int ind)
    {
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        bool ans=false;
        for(int i=ind+1;i<=s.size();i++)
        {
            string temp=s.substr(ind,i-ind);
            if(ss.count(temp))
            {
                ans=ans|getAns(s,i);
            }
        }
        return dp[ind]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &i:wordDict)
        {
            ss.insert(i);
        }
        memset(dp,-1,sizeof(dp));
        return getAns(s,0);
    }
};