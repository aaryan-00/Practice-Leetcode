class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        for(int i=1; i< strs.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
            {
                if(s[j]!=strs[i][j])
                {
                    s.resize(j);
                }
            }
        }
        return s;
    }
};