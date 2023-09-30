class Solution {
public:
    void dfs(vector<int> &vis, vector<pair<int, int>> adj[], int node, int &ans)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (vis[it.first] == 0)
            {
                ans = ans + it.second;
                dfs(vis, adj, it.first, ans);
            }
        }
    }

    void dfs2(vector<int> &vis, vector<pair<int, int>> adj[], int node, vector<int> &dp)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (vis[it.first] == 0)
            {
                if (it.second == 1)
                    it.second = -1;
                else
                    it.second = 1;
                dp[it.first] = dp[node] + it.second;
                    // cout << dp[it.first] << " " << it.first << " " << node.first << endl;
                dfs2(vis, adj, it.first, dp);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<":";
        //     for(auto it:adj[i])
        //     {
        //         cout<<it.first<<","<<it.second<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int>dp(n,0);

        int ans=0;
        vector<int> vis(n,0);

        int fl=0;
        dfs(vis,adj,0,ans);
        dp[0]=ans;

        fl=1;
        fill(vis.begin(),vis.end(),0) ;

        dfs2(vis,adj,0,dp);
        return dp;

    }
};