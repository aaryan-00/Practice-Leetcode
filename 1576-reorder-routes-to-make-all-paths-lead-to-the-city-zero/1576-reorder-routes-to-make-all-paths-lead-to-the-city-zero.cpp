class Solution {
public:
    set<pair<int,int>> s;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            // s.insert({v,u});
            s.insert({u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        int ans=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto i:adj[curr])
            {
                if(vis[i]==false)
                {
                    // if(s.find({i,curr})==s.end())
                    if(s.find({curr,i})!=s.end())
                    {
                        ans++;
                    }
                    q.push(i);
                }
            }  
        }
        // return n-1-ans;
        return ans;
    }
};