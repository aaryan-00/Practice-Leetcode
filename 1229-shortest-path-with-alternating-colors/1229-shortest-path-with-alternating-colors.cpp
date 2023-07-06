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
    }

};