class Solution {
public:
    int ans=INT_MAX;
    // void dfs(vector<pair<int,int>> adj[],int node,vector<bool> &vis)
    // {
    //     vis[node]=true;
    //     for(auto &i:adj[node])
    //     {
    //         ans=min(ans,i.second);
    //         if(!vis[i.first])
    //         {
    //             dfs(adj,i.first,vis);
    //         }
    //     }
    // }
    // int minScore(int n, vector<vector<int>>& roads) {
    //     vector<pair<int,int>> adj[n];
    //     for(auto &i:roads)
    //     {
    //         int u=i[0]-1;
    //         int v=i[1]-1;
    //         int wt=i[2];
    //         adj[u].push_back({v,wt});
    //         adj[v].push_back({u,wt});
    //     }
    //     vector<bool> vis(n,false);
    //     dfs(adj,0,vis);
    //     return ans;   
    // }

//union find
    vector<int> par;
    vector<int> sizes;
    void make(int v)
    {
        par[v] = v;
        sizes[v] = 1;
    }
    int find(int v)
    {
        if (par[v] == v)
            return v;
        return par[v] = find(par[v]);
    }
    void unionSet(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sizes[b] > sizes[a])
            {
                swap(b, a);
            }
            // if(b==1)
            // {
            //     swap(b,a);
            // }
            par[b] = a;
            sizes[a] += sizes[b];
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n+1);
        sizes.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            make(i);
        }
        for(auto i:roads)
        {
            unionSet(i[0],i[1]);
        }
        int parent=find(1);
        for(auto i:roads)
        {
            int curr_par=find(i[0]);
            if(parent==curr_par)
            {
                ans=min(ans,i[2]);
            }
        }
        return ans;
    }
};