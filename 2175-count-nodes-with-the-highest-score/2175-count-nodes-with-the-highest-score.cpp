class Solution {
public:
    vector<int> sub_sz;
    vector<vector<int>> adj;
    void dfs1(int node,int par)
    {
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                dfs1(child,node);
                sub_sz[node]+=sub_sz[child];
            }
        }
        sub_sz[node]++;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        int n=parents.size();
        adj.resize(n);
        sub_sz.resize(n,0);
        for(int i=1;i<n;i++)
        {
            int child=i,par=parents[i];
            adj[par].push_back(i);
        }
        dfs1(0,0);
        unordered_map<long long,long long> mp;
        for(int i=0;i<n;i++)
        {
            long long curr=0,curr_max=1;
            for(auto i:adj[i])
            {
                curr+=sub_sz[i];
                curr_max*=(long long)sub_sz[i];
            }
            int rem=n-curr-1;
            if(rem>0)
            {
                curr_max*=rem;
            }
            mp[curr_max]++;
        }
        long long maxi=1,val=0;
        for(auto i:mp)
        {
            if(i.first>val)
            {
                maxi=i.second;
                val=i.first;
            }
            
        }
        return maxi;
    }
};