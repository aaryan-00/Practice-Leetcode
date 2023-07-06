class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<redEdges.size();i++)
        {
            int u=redEdges[i][0],v=redEdges[i][1];
            adj[u].push_back({v,1});
        }
        for(int i=0;i<blueEdges.size();i++)
        {
            int u=blueEdges[i][0],v=blueEdges[i][1];
            adj[u].push_back({v,0});
        }

        vector<int> dis(n,-1);
        queue<vector<int>> q;
        q.push({0,-1,0});
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int node=curr[0],color=curr[1],dist=curr[2];
            if(dis[node]==-1)
            {
                dis[node]=dist;
            }
            for(auto &i:adj[node])
            {
                int curr_node=i.first;
                int curr_color=i.second;
                if(color!=curr_color && curr_color!=-1)
                {
                    q.push({curr_node,curr_color,dist+1});
                    i.second=-1;
                }
            }

        } 
        return dis;


        //         vector<int> dist(n,-1); 
        
        // queue<vector<int>> q;
        // q.emplace(vector<int>{0,0,-1});
        
        // while(!q.empty()) {
        //     auto front = q.front();
        //     q.pop();
        //     dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1];
            
        //     for(auto &i : adj[front[0]]) {
		// 		//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
		// 		//for the first time.
        //         if(front[2] != i.second && i.first!= -1) {
        //             q.emplace(vector<int>{i.first, front[1] + 1, i.second});
		// 			//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
        //             i.first = -1;
        //         }
        //     }
        // }
        // return dist;
    }

};