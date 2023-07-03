class Solution {
public:
    int ans=0;
    void dfs(int node,vector<int> adj[],vector<bool> &vis,set<int> &s)
    {
        ans++;
        vis[node]=true;
        for(auto i:adj[node])
        {
            if(!vis[i] && s.count(i)==0)
            {
                dfs(i,adj,vis,s);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        set<int> s;
        vector<bool> vis(n,false);
        for(auto i:restricted)
        {
            s.insert(i);
        }
        dfs(0,adj,vis,s);
        return ans;

    }
};