class Solution {
public:
    unordered_map<int,int> mp;
    int getVal(int i)
    {
        if(i==1) return 0;
        if(mp.find(i)!=mp.end()) return mp[i];
        if(i&1)
        {
            mp[i]=1+getVal(3*i+1);
        }
        else
        {
            mp[i]=1+getVal(i/2);
        }
        return mp[i];
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans.push_back({getVal(i),i});
            }
            else
            {
                ans.push_back({mp[i],i});
            }
        }
        // for(auto i:mp)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
        
    }
};