class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            adj[v].push_back(u);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};