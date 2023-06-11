class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            int u=trust[i][0],v=trust[i][1];
            adj[u]--,adj[v]++;
        }
        for(int i=1;i<adj.size();i++)
        {
            if(adj[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};