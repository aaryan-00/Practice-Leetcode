class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
        // for(int i=1; i< strs.size(); i++)
        // {
        //     for(int j=0; j<s.size(); j++)
        //     {
        //         if(s[j]!=strs[i][j])
        //         {
        //             s.resize(j);
        //         }
        //     }
        // }
        // return s;


        // int n=s.size();
        // for(int i=1; i< strs.size(); i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         if(s[j]!=strs[i][j])
        //         {
        //             n=j;
        //         }
        //     }
        // }
        // return s.substr(0,n);

        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }
};