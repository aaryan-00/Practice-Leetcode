class Solution {
public:
    // void bfs(vector<int> adj[],int src,vector<int> &dis)
    // {
    //     queue<int> q;
    //     q.push(src);
    //     dis[src]=0;
    //     while(!q.empty())
    //     {
    //         int node=q.front();
    //         q.pop();
    //         for(auto it:adj[node])
    //         {
    //             if(dis[it]==-1)
    //             {
    //                 dis[it]=dis[node]+1;
    //                 q.push(it);
    //             }
    //         }
    //     }
    // }
    void bfs2(vector<int>& edges,int src,vector<int> &dis)
    {
        queue<int> q;
        q.push(src);
        dis[src]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(edges[u]!=-1 )
            {
                if(dis[edges[u]]==-1)
                {
                    dis[edges[u]]=dis[u]+1;
                    q.push(edges[u]);
                }    
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        // vector<int> adj[n];
        // for(int i=0;i<n;i++)
        // {
        //     if(edges[i]==-1) continue;
        //     int u=i;
        //     int v=edges[i];
        //     adj[u].push_back(v);
        // }
        // vector<int> dis1(n,-1);
        // bfs(adj,node1,dis1);
        // vector<int> dis2(n,-1);
        // bfs(adj,node2,dis2);

        vector<int> dis1(n,-1);
        bfs2(edges,node1,dis1);
        vector<int> dis2(n,-1);
        bfs2(edges,node2,dis2);
        // for(auto i:dis1)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:dis2)
        // {
        //     cout<<i<<" ";
        // }
        int ans=INT_MAX;
        int node=-1;
        for(int i=0;i<n;i++)
        {
            if(dis1[i]!=-1 && dis2[i]!=-1)
            {
                int curr=max(dis1[i],dis2[i]);
                if(curr<ans)
                {
                    ans=curr;
                    node=i;
                }
            }
        }
        return node;
    }
};