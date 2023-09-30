class Solution {
public:
    void dfs(vector<int> &vis, vector<pair<int, int>> adj[], pair<int, int> node, int &ans, vector<int> &dp, int &fl)
    {
        // if(vis[node.first]==1) return ;
        vis[node.first] = 1;

        for (auto it : adj[node.first])
        {
            if (vis[it.first] == 0)
            {
                ans = ans + it.second;
                if (fl == 1)
                {
                    if (it.second == 1)
                        it.second = -1;
                    else
                        it.second = 1;
                    dp[it.first] = dp[node.first] + it.second;
                    // cout << dp[it.first] << " " << it.first << " " << node.first << endl;
                }
                dfs(vis, adj, it, ans, dp, fl);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            // for(int j=0;j<edges[i].size();j++){
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            // }
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
        vector<int>v(n,0);
        vector<int>dp(n,0);

        int ans=0;
        vector<int> vis(n+1,0);

        int fl=0;
        dfs(vis,adj,{0,adj[0][0].second},ans,dp,fl);
        dp[0]=ans;
        // cout<<ans<<"ans";

        fl=1;
        fill(vis.begin(),vis.end(),0) ;
        // cout<<adj[0][0].second ;
        dfs(vis,adj,{0,adj[0][0].second},ans,dp,fl);
        for(int i=0;i<n;i++) v[i]=dp[i] ;
        return v ;
        // vector<int>dp(n,0) ;

    }
};