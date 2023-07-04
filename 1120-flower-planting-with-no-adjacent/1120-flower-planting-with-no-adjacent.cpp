class Solution {
public:
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
    //         if(color[ind]==-1)
    //         {
    //             q.push(ind);
    //             while(!q.empty())
    //             {
    //                 int curr=q.front();
    //                 q.pop();
    //                 vector<int> temp(5,0);
    //                 for(auto i:adj[curr])
    //                 {
    //                     if(color[i]==-1)
    //                     {
    //                         q.push(i);
    //                     }
    //                     else
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
    //             }
    //         }
    //     }
    //     return color;
    // }
    vector<int> bfs2(int n,vector<vector<int>>& graph) {
        
        vector<bool> visited(n, false);
        vector<int> node_color(n, -1);
        
        for(int node = 0; node < node_color.size(); node++) {
            // unprocessed node
            if(!visited[node]) {
                queue<int> q;
                q.push(node);
                // Since this is the 1st node of a disconnected component,
                // we can start with color 1
                // node_color[node] = 1;
                visited[node] = true;
                
                while(!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    
                    // check the color of neighboring nodes
                    vector<bool> color_used(4, false);

                    for(auto neighbor: graph[curr])
                        if(node_color[neighbor] != -1)
                            color_used[node_color[neighbor] - 1] = true;

                    // pick the first unused color for the current node
                    for(int color = 0; color < 4; color++)
                        if(color_used[color] == false) {
                            // color the source node
                            node_color[curr] = color + 1;
                            break;
                        }
                    // traverse the unvisited neighbor
                    for(auto neighbor: graph[curr])
                        if(!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                }
            }
        }
        return node_color;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto i:paths)
        {
            int u=i[0]-1,v=i[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return bfs2(n,adj);
    }

};