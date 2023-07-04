class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        for(auto i:paths)
        {
            int u=i[0]-1,v=i[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n,-1);
        queue<int> q;
        for(int ind=0;ind<n;ind++)
        {
            if(color[ind]==-1)
            {
                q.push(ind);
                while(!q.empty())
                {
                    int curr=q.front();
                    // cout<<curr<<endl;
                    q.pop();
                    vector<int> temp(5,0);
                    for(auto i:adj[curr])
                    {
                        if(color[i]==-1)
                        {
                            q.push(i);
                        }
                        else
                        {
                            int col=color[i];
                            temp[col]=1;
                        }
                    }
                    for(int i=1;i<5;i++)
                    {
                        if(temp[i]==0)
                        {
                            color[curr]=i;
                            break;
                        }
                    }
                }
            }
        }
        return color;
        

    }
};