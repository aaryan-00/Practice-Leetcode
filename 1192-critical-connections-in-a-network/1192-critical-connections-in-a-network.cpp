class Solution {
public:
    vector<vector<int>> ans;
    int timer=0;
    void dfs(int node,int par,vector<bool>& vis,vector<int>&time,vector<int>&timeLow,vector<int> adj[])
    {
        vis[node]=true;
        time[node]=timeLow[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==par) continue;
            if(vis[it]==false)
            {
                dfs(it,node,vis,time,timeLow,adj);
                timeLow[node]=min(timeLow[it],timeLow[node]);
                if(timeLow[it]>time[node])
                {
                    ans.push_back({it,node});
                }
            }
            else
            {
                timeLow[node]=min(timeLow[it],timeLow[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto i:connections)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> time(n),timeLow(n);
        vector<bool> vis(n,false);
        ans.clear();
        dfs(0,-1,vis,time,timeLow,adj);
        return ans;
    }
};