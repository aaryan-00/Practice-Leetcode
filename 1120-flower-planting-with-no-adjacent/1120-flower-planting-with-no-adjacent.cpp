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
                    q.pop();
                    // cout<<curr<<endl;
                    if(color[curr]!=-1) continue;
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


//more optimised as visited node do not enters

    // vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    //     vector<int> adj[n];
    //     for(auto i:paths)
    //     {
    //         int u=i[0]-1,v=i[1]-1;
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //     }
    //     vector<int> color(n,-1);
    //     vector<int> vis(n,0);
    //     queue<int> q;
    //     for(int ind=0;ind<n;ind++)
    //     {
    //         if(!vis[ind])
    //         {
    //             q.push(ind);
    //             vis[ind]=1;
    //             while(!q.empty())
    //             {
    //                 int curr=q.front();
    //                 q.pop();
    //            //    cout<<curr<<endl;
    //                 vector<int> temp(5,0);
    //                 for(auto i:adj[curr])
    //                 {
    //                     if(color[i]!=-1)
    //                     {
    //                         int col=color[i];
    //                         temp[col]=1;
    //                     }
    //                 }
    //                 for(int i=1;i<5;i++)
    //                 {
    //                     if(temp[i]==0)
    //                     {
    //                         color[curr]=i;
    //                         break;
    //                     }
    //                 }
    //                 for(auto i:adj[curr])
    //                 {
    //                     if(!vis[i])
    //                     {
    //                         q.push(i);
    //                         vis[i]=1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return color;
    // }

//greeedy
    // vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    //     vector<int> adj[n];
    //     for(auto i:paths)
    //     {
    //         int u=i[0]-1,v=i[1]-1;
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //     }
    //     vector<int> color(n,-1);
    //     queue<int> q;
    //     for(int ind=0;ind<n;ind++)
    //     {
    //         vector<bool> temp(5,false);
    //         for(auto i:adj[ind])
    //         {
    //             if(color[i]!=-1) temp[color[i]]=true;
    //         }
    //         for(int i=1;i<5;i++)
    //         {
    //             if(temp[i]==false)
    //             {
    //                 color[ind]=i;
    //                 break;
    //             }
    //         }

    //     }
    //     return color;
    // }

};