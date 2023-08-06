class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> hashh(26,0);
        for(auto i:s1)
        {
            hashh[i-'a']++;
        }
        vector<int> check (26, 0);
        int start=0,end=0;
        while (end < s2.size()) {
            check[s2[end]-'a']++;
            if (end - start + 1 == s1.size()) 
            {
                if (hashh == check) return true;
            }
            if (end - start + 1 < s1.size()) 
            {
                end++;
            }
            else {
                check[s2[start]-'a']--;
                start++;
                end++;
            }
        }

        // int k=s1.size()-1;
        // for(int i=k;i<s2.size();i++)
        // {
            
        //     for(int j=start;j<=i;j++)
        //     {
        //         check[s2[j]-'a']++;
        //         // cout<<s2[j]-'a'<<" ";
        //     }
        //     // cout<<endl;
        //     if(check==hashh) return true;

        //     start++;
        // }
        return false;
    }
};