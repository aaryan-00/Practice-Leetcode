class Solution {
public:
    vector<string> info={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string temp;
    // void combi(int ind,string &digits)
    // {
    //     if(ind==digits.size() && temp.size()==digits.size())
    //     {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=ind;i<digits.size();i++)
    //     {
    //         int curr=digits[i]-'0';
    //         // cout<<curr<<endl;
    //         string s=info[curr];
    //         for(int j=0;j<s.size();j++)
    //         {
    //             temp+=s[j];
    //             combi(i+1,digits);
    //             temp.pop_back();
    //         }
    //     }
    // }

    void combi(int ind,string &digits)
    {
        if(ind==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int curr=digits[ind]-'0';
        string s=info[curr];
        for(int j=0;j<s.size();j++)
        {
            temp+=s[j];
            combi(ind+1,digits);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        ans.clear();
        // temp.clear();
        combi(0,digits);
        return ans;
    }
};