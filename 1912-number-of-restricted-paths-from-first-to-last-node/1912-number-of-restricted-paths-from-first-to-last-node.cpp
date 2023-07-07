class Solution {
public:
    const int m=1e9+7;
    vector<long> dijkstra(int n,vector<vector<int>> adj[],int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<long> dis(n, INT_MAX);
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
                int next=i[0];
                int next_dis=i[1];
                if(dis[next]>dis[node]+next_dis)
                {
                    dis[next]=dis[node]+next_dis;
                    pq.push({dis[next],next});
                }
            }   
        }
        return dis;

    }
    vector<long> cnt;
    // int ans=0;
    int dfs(vector<vector<int>> adj[],int src,vector<long> &dis)
    {
        // if(src==dis.size()-1) ans++;
        // ans%=m;
        if(src==dis.size()-1) return 1;
        if(cnt[src]!=-1) return cnt[src];
        long curr=0;
        for(auto i:adj[src])
        {
            long node=i[0];
            if(dis[node]<dis[src])
            {
                // cnt[node]+=1;
                // cnt[node]%=m;
                curr=(curr+dfs(adj,node,dis))%m;
            }
        }
        return cnt[src]=curr%m;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj[n];
        for(auto i:edges)
        {
            int u=i[0]-1;
            int v=i[1]-1;
            int wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long> dis=dijkstra(n, adj,n-1);
        cnt.resize(n,-1);
        // cnt[0]=1;
        dfs(adj,0,dis);
        // for(auto i:cnt)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return cnt[0];
        
    }
};