class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string,vector<string>> mp;
    //     for(auto i:strs)
    //     {
    //         string curr=i;
    //         sort(curr.begin(),curr.end());
    //         mp[curr].push_back(i);
    //     }
    //     vector<vector<string>> ans;
    //     for(auto i:mp)
    //     {
    //         ans.push_back(i.second);
    //     }
    //     return ans;
    // }


    string sortLowercase(string s) {
        int charExist[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            charExist[s[i] - 'a']++;
        }
        string res;
        int j = 0;
        while (j < 26) {
            if (charExist[j] == 0) {
                j++;
            }
            else {
                res.push_back(j + 'a');
                charExist[j]--;
            }
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto i:strs)
        {
            string curr=sortLowercase(i);
            mp[curr].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};