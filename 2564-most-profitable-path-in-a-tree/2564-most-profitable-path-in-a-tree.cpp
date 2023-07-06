class Solution {
public:
    bool dfs(int src, vector<int> adj[],vector<bool> &vis, int time,vector<int> &steps)
    {
        vis[src]=true;
        steps[src]=time;
        if(src==0)
        {
            return true;
        }
        for(auto i:adj[src])
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,time+1,steps))
                {
                    return true;
                }
            }
        }
        steps[src]=-1;
        return false;
    }
    int ans=INT_MIN;
    void dfs2(int src,vector<int> adj[],vector<bool> &vis,vector<int>& amount,int time,vector<int> &steps,int cost)
    {
        if(time<steps[src]||steps[src]==-1)
        {
            cost+=amount[src];
        }
        if(time==steps[src])
        {
            cost+=amount[src]/2;
        }
        cout<<src<<" "<<cost<<endl;
        
        vis[src]=true;
        if(adj[src].size()==1 && src!=0) ans=max(ans,cost);
        for(auto i:adj[src])
        {
            if(!vis[i])
            {
                dfs2(i,adj,vis,amount,time+1,steps,cost);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int> adj[n];
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> steps(n,-1);
        vector<bool> vis(n,false); 
        dfs(bob,adj,vis,0,steps);
        for(auto i:steps)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        vector<bool> vis2(n,false); 
        dfs2(0,adj,vis2,amount,0,steps,0);
        return ans;

        
    }
};