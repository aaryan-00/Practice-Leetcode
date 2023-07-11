class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool checkPalindrome(string &s,int l,int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r]) return false;
            l++;r--;
        }
        return true;
    }
    void partitioning(string &s,int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(checkPalindrome(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                partitioning(s,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        ans.clear();
        temp.clear();
        partitioning(s,0);
        return ans;
    }
};