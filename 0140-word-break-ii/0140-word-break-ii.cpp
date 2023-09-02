class Solution {
public:
    // unordered_set<string> ss;
    // vector<string> ans;
    // vector<string> curr;
    // void getAns(string &s,int ind)
    // {
    //     if(ind==s.size()) 
    //     {
            
    //         if(curr.size()>0)
    //         {
    //             string alpha="";
    //             for(auto &i:curr)
    //             {
    //                 alpha+=i;
    //                 alpha+=" ";
    //             }
    //             alpha.pop_back();
    //             ans.push_back(alpha);
    //         }
    //         return;
    //     }
    //     for(int i=ind+1;i<=s.size();i++)
    //     {
    //         string temp=s.substr(ind,i-ind);
    //         if(ss.count(temp))
    //         {
    //             curr.push_back(temp);
    //             getAns(s,i);
    //             curr.pop_back();
    //         }
    //     }
    // }
    // vector<string> wordBreak(string s, vector<string>& wordDict) {
    //     for(auto &i:wordDict)
    //     {
    //         ss.insert(i);
    //     }
    //     ans.clear();
    //     getAns(s,0);
    //     return ans;
    // }


    unordered_set<string> ss;
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
        string temp="";
        for(int i=ind;i<s.size();i++)
        {
            temp+=s[i];
            if(ss.count(temp))
            {
                curr.push_back(temp);
                getAns(s,i+1);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &i:wordDict)
        {
            ss.insert(i);
        }
        ans.clear();
        getAns(s,0);
        return ans;
    }
};