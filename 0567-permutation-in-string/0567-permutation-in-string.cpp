class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hashh(26,0);
        for(auto i:s1)
        {
            hashh[i-'a']++;
            // cout<<i-'a'<<endl;
        }
        int k=s1.size()-1;
        int start=0;
        for(int i=k;i<s2.size();i++)
        {
            vector<int> check(26,0);
            for(int j=start;j<=i;j++)
            {
                check[s2[j]-'a']++;
                // cout<<s2[j]-'a'<<" ";
            }
            // cout<<endl;
            if(check==hashh) return true;

            start++;
        }
        return false;
    }
};