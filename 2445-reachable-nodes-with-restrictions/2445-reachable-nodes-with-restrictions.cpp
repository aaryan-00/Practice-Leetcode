class Solution {
public:
    // int ans=0;
    // void dfs(int node,vector<int> adj[],vector<bool> &vis,set<int> &s)
    // {
    //     ans++;
    //     vis[node]=true;
    //     for(auto i:adj[node])
    //     {
    //         if(!vis[i] && s.count(i)==0)
    //         {
    //             dfs(i,adj,vis,s);
    //         }
    //     }
    // }
    // int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    //     vector<int> adj[n];
    //     for(auto i:edges)
    //     {
    //         adj[i[0]].push_back(i[1]);
    //         adj[i[1]].push_back(i[0]);
    //     }
    //     set<int> s;
    //     vector<bool> vis(n,false);
    //     for(auto i:restricted)
    //     {
    //         s.insert(i);
    //     }
    //     dfs(0,adj,vis,s);
    //     return ans;
    // }


//using parent
    // int ans=0;
    // void dfs(int node,int par,vector<int> adj[],set<int> &s)
    // {
    //     ans++;
    //     for(auto i:adj[node])
    //     {
    //         if(i!=par && s.count(i)==0)
    //         {
    //             dfs(i,node,adj,s);
    //         }
    //     }
    // }
    // int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    //     vector<int> adj[n];
    //     for(auto i:edges)
    //     {
    //         adj[i[0]].push_back(i[1]);
    //         adj[i[1]].push_back(i[0]);
    //     }
    //     set<int> s;
    //     for(auto i:restricted)
    //     {
    //         s.insert(i);
    //     }
    //     dfs(0,-1,adj,s);
    //     return ans;
    // }



//here we marked restricted node visited, so there is no going to their subtrees
    // int ans=0;
    // void dfs(int node,vector<int> adj[],vector<bool> &vis)
    // {
    //     ans++;
    //     vis[node]=true;
    //     for(auto i:adj[node])
    //     {
    //         if(!vis[i])
    //         {
    //             dfs(i,adj,vis);
    //         }
    //     }
    // }
    // int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    //     vector<int> adj[n];
    //     for(auto i:edges)
    //     {
    //         adj[i[0]].push_back(i[1]);
    //         adj[i[1]].push_back(i[0]);
    //     }
    //     vector<bool> vis(n,false);
    //     for(auto i:restricted)
    //     {
    //         vis[i]=true;
    //     }
    //     dfs(0,adj,vis);
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
            // if (sizes[b] > sizes[a])
            // {
            //     swap(b, a);
            // }
            if(b==0)
            {
                swap(a,b);
            }
            par[b] = a;
            sizes[a] += sizes[b];
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        par.resize(n);
        sizes.resize(n);
        vector<bool> res(n,false);
        for(auto i:restricted)
        {
            res[i]=true;
        }
        for(int i=0;i<n;i++)
        {
            make(i);
        }
        for(auto i:edges)
        {
            if(res[i[0]]==false && res[i[1]]==false)
            {
                unionSet(i[0],i[1]);
            }
        }
        // cout<<sizes[1]<<" "<<sizes[0]<<endl;
        return sizes[0];
    }



};