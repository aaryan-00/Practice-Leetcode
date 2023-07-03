class Solution {
public:
    int mini=INT_MAX;
    void dfs(vector<pair<int,int>> adj[],int node,vector<bool> &vis)
    {
        vis[node]=true;
        for(auto &i:adj[node])
        {
            mini=min(mini,i.second);
            if(!vis[i.first])
            {
                dfs(adj,i.first,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto &i:roads)
        {
            int u=i[0]-1;
            int v=i[1]-1;
            int wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<bool> vis(n,false);
        dfs(adj,0,vis);
        
        return mini;   
    }
};