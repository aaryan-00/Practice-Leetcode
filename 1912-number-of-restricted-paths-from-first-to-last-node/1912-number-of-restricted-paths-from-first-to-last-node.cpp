class Solution {
public:
    const int m=1e9+7;
    vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n, INT_MAX);
        pq.push({0, src});
        dis[src] = 0;
        while(!pq.empty())
        {
            pair<int,int> curr=pq.top();
            pq.pop();
            int Dis=curr.first;
            int node=curr.second;
            if(Dis>dis[node]) continue;
            for(auto i:adj[node])
            {
                int next=i.first;
                int next_dis=i.second;
                if(dis[next]>dis[node]+next_dis)
                {
                    dis[next]=dis[node]+next_dis;
                    pq.push({dis[next],next});
                }
            }   
        }
        return dis;

    }

    int dfs(vector<vector<pair<int,int>>> &adj,int src,vector<int> &dis,vector<int> &cnt)
    {
        if(src==0) return 1;
        if(cnt[src]!=-1) return cnt[src];
        int curr=0;
        for(auto i:adj[src])
        {
            int node=i.first;
            if(dis[node]>dis[src])
            {
                curr+=dfs(adj,node,dis,cnt);
                curr%=m;
            }
        }
        return cnt[src]=curr%m;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:edges)
        {
            int u=i[0]-1;
            int v=i[1]-1;
            int wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dis=dijkstra(n, adj,n-1);
        vector<int> cnt(n,-1);
        dfs(adj,n-1,dis,cnt);
        // for(auto i:cnt)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return cnt[n-1];   
    }
};