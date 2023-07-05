class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(auto i:dislikes)
        {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                queue<int> q;
                col[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node])
                    {
                        if(col[it]==-1)
                        {
                            q.push(it);
                            col[it]=1-col[node];
                        }
                        else if(col[it]==col[node])
                        {
                            return false;
                        }
                        
                    }
                }
            }
        }
        return true;
    }
};