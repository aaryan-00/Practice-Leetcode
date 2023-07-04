class Solution {
public:
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
        
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int> dis(V,INT_MAX);
//         pq.push({0,S});
//         dis[S]=0;
//         while(!pq.empty())
//         {
//             pair<int,int> curr=pq.top();
//             pq.pop();
//             int prevDis=curr.first;
//             int currInd=curr.second;
//             for(auto i:adj[currInd])
//             {
//                 int nextInd=i[0];
//                 int nextDis=i[1];
//                 if(dis[nextInd]>nextDis+prevDis)
//                 {
//                     dis[nextInd]=nextDis+prevDis;
//                     pq.push({dis[nextInd],nextInd});
//                 }
                
//             }
//         }
//         return dis;
//     }
//     int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
//         int n=patience.size();
//         vector<vector<int>> adj[n];
//         for(auto i:edges)
//         {
//             int u=i[0],v=i[1];
//             adj[u].push_back({v,1});
//             adj[v].push_back({u,1});
            
//         }
//         vector<int> dis=dijkstra(n,adj,0);
// //bellman ford
//         // vector<int> dis2(n,1e8);
//         // dis2[0]=0;
//         // for(int i=0;i<n-1;i++)
//         // {
//         //     for(auto it:edges)
//         //     {
//         //         int u=it[0];
//         //         int v=it[1];
//         //         int wt=1;
//         //         if(dis2[u]!=1e8 && dis2[u]+wt<dis2[v])
//         //         {
//         //             dis2[v]=dis2[u]+wt;
//         //         }
//         //         if(dis2[v]!=1e8 && dis2[v]+wt<dis2[u])
//         //         {
//         //             dis2[u]=dis2[v]+wt;
//         //         }
//         //     }
//         // }

//         // for(int i=0;i<n;i++)
//         // {
//         //     cout<<dis[i]<<" "<<dis2[i]<<endl;
//         // }

//         int ans=0;
//         for(int i=1;i<n;i++)
//         {
//             int curr_dis=dis[i]*2;
//             if(curr_dis%patience[i]==0)
//             {
//                 int temp=curr_dis*2+1-patience[i];
//                 ans=max(ans,temp);
//             }
//             else
//             {
//                 int temp=curr_dis*2+1-curr_dis%patience[i];
//                 ans=max(ans,temp);
//             }
//         }
//         return ans;



//         // int ans=0;
//         // for(int i=1;i<n;i++)
//         // {
//         //     int time=dis[i]*2;
//         //     int p=patience[i];
//         //     int numb=time/p;
//         //     if(time%p==0)
//         //     {
//         //         numb--; 
//         //     }
//         //     int last=numb*p;
//         //     int temp=2*dis[i]+last+1;
//         //     ans=max(ans,temp);
//         // }
//     }


//bfs
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector <vector <int>> graph(n);
        vector <int> dis(n, -1);
        
        for(auto x: edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        queue <int> q;
        q.push(0);
        dis[0] = 0;
        while(q.size()) {
            int node = q.front();
            q.pop();
            for(auto child: graph[node]) {
                if(dis[child] == -1) { 
                    dis[child] = dis[node] + 1;
                    q.push(child);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int curr_dis=dis[i]*2;
            if(curr_dis%patience[i]==0)
            {
                int temp=curr_dis*2+1-patience[i];
                ans=max(ans,temp);
            }
            else
            {
                int temp=curr_dis*2+1-curr_dis%patience[i];
                ans=max(ans,temp);
            }
        }
        return ans;


    }
};