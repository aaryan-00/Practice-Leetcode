class Solution {
public:
    long long ans=0;
    long long dfs(int src,int par,vector<vector<int>> &adj,int seats)
    {
        long long rep=1;
        for(auto i:adj[src])
        {
            if(par!=i)
            {
                rep+=dfs(i,src,adj,seats);
            }
        }
        if(src!=0)
        {
            ans+=ceil(double(rep)/seats);
        }
        // cout<<rep<<" "<<src<<endl;
        return rep;
    }
    void bfs(vector<int> &indegree,vector<vector<int>> &adj,int seats)
    {
        queue<int> q;
        for(int i=1;i<indegree.size();i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        vector<int> rep(indegree.size(),1);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans+=ceil(double(rep[curr])/seats);
            for(auto i:adj[curr])
            {
                rep[i]+=rep[curr];
                indegree[i]--;
                if(indegree[i]==1 && i!=0)
                {
                    q.push(i);
                }
            }

        }

    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long n=roads.size()+1;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i:roads)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        // dfs(0,-1,adj,seats);
        for(auto i:indegree)
        {
            cout<<i<<" ";
        }
        bfs(indegree,adj,seats);
        return ans;
    }
};