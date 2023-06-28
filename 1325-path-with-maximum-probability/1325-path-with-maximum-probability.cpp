class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        vector<double> dp(n,0);
        dp[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty())
        {
            int node=pq.top().second;
            double prob=pq.top().first;
            pq.pop();
            for(auto i:adj[node])
            {
                int next=i.first;
                double nextprob=i.second;
                if(dp[next]<nextprob*prob)
                {
                    dp[next]=nextprob*prob;
                    pq.push({dp[next],next});
                }
            }
        }
        if(dp[end]==-1)
        {
            return 0;
        }
        return dp[end];
    }
};