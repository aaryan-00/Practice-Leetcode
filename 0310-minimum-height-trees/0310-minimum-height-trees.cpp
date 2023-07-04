class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            vector<int> temp;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int curr=q.front();
                temp.push_back(curr);
                q.pop();
                for(auto i:adj[curr])
                {
                    indegree[i]--;
                    if(indegree[i]==1)
                    {
                        q.push(i);
                    }
                }
            }
            ans=temp;
        }
        return ans;


    }
};