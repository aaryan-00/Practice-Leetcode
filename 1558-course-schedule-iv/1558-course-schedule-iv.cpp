class Solution {
public:
    void dfs(vector<int> adj[],int src,vector<bool> &vis,int ind,vector<set<int>> &check)
    {
        vis[src]=true;
        for(auto i:adj[src])
        {
            if(!vis[i])
            {
                check[ind].insert(i);
                dfs(adj,i,vis,ind,check);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<int> adj[n];
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<set<int>> check(n);
        set<pair<int,vector<int>>> s;
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,0);
            dfs(adj,i,vis,i,check);

        }
        vector<bool> ans;
        for(auto i:queries)
        {
            if(check[i[0]].count(i[1])) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};