class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:flights)
        {
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> prices(n,INT_MAX);
        prices[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stop=q.front().first;
            int Ind=q.front().second.first;
            int Price=q.front().second.second;
            q.pop();
            if(stop>k) continue;
            for(auto i:adj[Ind])
            {
                int nextInd=i.first;
                int nextPrice=i.second;
                if(prices[nextInd]>nextPrice+Price && stop<=k)
                {
                    prices[nextInd]=nextPrice+Price;
                    q.push({stop+1,{nextInd,prices[nextInd]}});
                }

            }
        }
        if(prices[dst]==INT_MAX) return -1;
        return prices[dst];

    }
};