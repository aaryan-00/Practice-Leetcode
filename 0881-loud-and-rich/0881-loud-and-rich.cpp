class Solution {
public:
    int dfs(int i,vector<int> &quiet,vector<vector<int>>& adj,vector<int> &ans)
    {
        if(ans[i]>=0) return ans[i];

        ans[i]=i;
        for(auto it:adj[i])
        {
            int ind=dfs(it,quiet,adj,ans);
            if(quiet[ans[i]]>quiet[ind])
            {
                // ans[i]=ind;
                ans[i]=ans[it];
            }
        }
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(auto i:richer)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            dfs(i,quiet,adj,ans);
        }
        return ans;
    }
};