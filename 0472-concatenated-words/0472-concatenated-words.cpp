class Solution {
public:
    // unordered_set<string> ss;
    // bool getAns(string &s,int ind,vector<int> &dp)
    // {
    //     if(ind==s.size()) return true;
    //     if(dp[ind]!=-1) return dp[ind];
    //     string temp="";
    //     for(int i=ind;i<s.size();i++)
    //     {
    //         temp+=s[i];
    //         if(ss.count(temp) && temp.size()<s.size())
    //         {
    //             if(getAns(s,i+1,dp))
    //             {
    //                 return dp[ind]=true;
    //             }
    //         }
    //     }
    //     return dp[ind]=false;
    // }
    // vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    //     for(auto &i:words)
    //     {
    //         ss.insert(i);
    //     }

    //     vector<string> ans;
    //     for(auto &i:words)
    //     {
    //         vector<int> dp(i.size(), -1);
    //         if(getAns(i,0,dp))
    //         {
                
    //             ans.push_back(i);
    //         }
    //     }
    //     return ans;
    // }

    unordered_set<string> ss;
    vector<int> dp;
    bool getAns(string &s,int ind)
    {
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        bool ans=false;
        string temp="";
        for(int i=ind;i<s.size();i++)
        {
            temp+=s[i];
            if(ss.count(temp) && temp!=s)
            {
                if(getAns(s,i+1)) return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &i:words)
        {
            ss.insert(i);
        }
        vector<string> ans;
        for(auto &i:words)
        {
            dp.clear();
            dp.resize(i.size(),-1);
            if(getAns(i,0))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

};