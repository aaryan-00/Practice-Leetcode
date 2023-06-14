class Solution {
public:
    int par[1001];
    int sizes[1001];
    void make(int v)
    {
        par[v] = v;
        sizes[v] = 1;
    }
    int find(int v)
    {
        if (par[v] == v)
            return v;
        return par[v] = find(par[v]);
    }
    void unionSet(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sizes[b] > sizes[a])
            {
                swap(b, a);
            }
            par[b] = a;
            sizes[a] += sizes[b];
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<points.size()-1;i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int u=i,v=j,w=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj.push_back({w,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        for(int i=0;i<n;i++)
        {
            make(i);
        }
        int ans=0;
        for(int i=0;i<adj.size();i++)
        {
            int wt=adj[i].first;
            int u=adj[i].second.first;
            int v=adj[i].second.second;
            if(find(u)!=find(v))
            {
                unionSet(u,v);
                ans+=wt;
            }
        }
        return ans;
    }
};