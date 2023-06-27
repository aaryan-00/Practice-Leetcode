class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
        int prev=0;
        for(auto i:s)
        {
            int val=mp[i];
            cout<<prev<<" "<<val<<endl;
            if(prev<val)
            {
                ans+=val-2*prev;
                prev=val;
            }
            else
            {
                ans+=val;
                prev=val;
            }
            
        }
        return ans;
    }
};