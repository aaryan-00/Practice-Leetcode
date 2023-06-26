class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto i:roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        long long M=1e9+7;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dis(n+1,1e15);
        vector<long long> ways(n+1,0);
        ways[0]=1;
        dis[0]=0;
        pq.push({0,0});

        while(!pq.empty())
        {
            long long Dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            if(dis[node]<Dis) continue;
            for(auto i:adj[node])
            {
                long long next=i.first;
                long long nextDis=i.second;
                if((nextDis+Dis)==dis[next])
                {
                    ways[next]=(ways[next]+ways[node])%M;
                    // dis[next]=nextDis+Dis;
                    // pq.push({dis[next],next});
                }
                if((nextDis+Dis)<dis[next])
                {
                    ways[next]=ways[node]%M;
                    dis[next]=(nextDis+Dis);
                    pq.push({dis[next],next});
                }
            }
        }
        return ways[n-1];
    }
};