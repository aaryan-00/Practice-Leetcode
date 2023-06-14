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
        int ans=-1;
        for(int i=n-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                int curr=indegree[i]+indegree[j];
                if(s.count({i,j})||s.count({j,i}))
                {
                    curr--;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};