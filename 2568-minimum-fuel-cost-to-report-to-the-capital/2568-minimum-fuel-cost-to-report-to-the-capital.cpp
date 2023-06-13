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
        return rep;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long n=roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto i:roads)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,seats);
        return ans;
    }
};