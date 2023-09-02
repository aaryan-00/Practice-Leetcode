class Solution {
public:
    unordered_set<string> ss;
    // int dp[301];
    // vector<int> dp;
    vector<string> ans;
    vector<string> curr;
    void getAns(string &s,int ind)
    {
        if(ind==s.size()) 
        {
            
            if(curr.size()>0)
            {
                string alpha="";
                for(auto &i:curr)
                {
                    alpha+=i;
                    alpha+=" ";
                }
                alpha.pop_back();
                ans.push_back(alpha);
            }
            return;
        }
        // if(dp[ind]!=-1) return dp[ind];
        bool ans=false;
        for(int i=ind+1;i<=s.size();i++)
        {
            string temp=s.substr(ind,i-ind);
            if(ss.count(temp))
            {
                curr.push_back(temp);
                getAns(s,i);
                curr.pop_back();
            }
        }
        // return dp[ind]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &i:wordDict)
        {
            ss.insert(i);
        }
        // memset(dp,-1,sizeof(dp));
        // dp.resize(s.size(),-1);
        ans.clear();
        getAns(s,0);
        return ans;
    }
};