class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(V,INT_MAX);
        pq.push({0,S});
        dis[S]=0;
        while(!pq.empty())
        {
            pair<int,int> curr=pq.top();
            pq.pop();
            int prevDis=curr.first;
            int currInd=curr.second;
            for(auto i:adj[currInd])
            {
                int nextInd=i[0];
                int nextDis=i[1];
                if(dis[nextInd]>nextDis+prevDis)
                {
                    dis[nextInd]=nextDis+prevDis;
                    pq.push({dis[nextInd],nextInd});
                }
                
            }
        }
        return dis;
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>> adj[n];
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
            
        }
        vector<int> dis=dijkstra(n,adj,0);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int time=dis[i]*2;
            int p=patience[i];
            int numb=time/p;
            if(time%p==0)
            {
                numb--; 
            }
            int last=numb*p;
            int temp=2*dis[i]+last+1;
            ans=max(ans,temp);
        }
        return ans;
    }
};