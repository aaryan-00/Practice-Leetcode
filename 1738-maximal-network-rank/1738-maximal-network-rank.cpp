class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        set<pair<int,int>> s;
        for(auto i:roads)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
            s.insert({i[0],i[1]});
        }
        vector<pair<int,int>> pa;
        for(int i=0;i<n;i++)
        {
            pa.push_back({indegree[i],i});
        }
        sort(pa.begin(),pa.end());
        int ans=-1;
        for(int i=n-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                int curr=pa[j].first+pa[i].first;
                int u=pa[j].second,v=pa[i].second;
                if(s.count({u,v})||s.count({v,u}))
                {
                    curr--;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};