class Solution {
public:
    int res=0;
    int getAns(int src,int par,int k, vector<int> adj[],vector<int> &val)
    {
        int ans=0;
        for(auto &i:adj[src])
        {
            if(i!=par)
            {
                ans+=getAns(i,src,k,adj,val);   
            }
            
        }
        ans+=val[src];
        if(ans%k==0) 
        {
            res++;
            ans=0;
        }
        return ans;
        

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        getAns(0,-1,k,adj,values);
        return res;

    }
};