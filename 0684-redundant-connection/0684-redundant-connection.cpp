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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=1;i<=n;i++)
        {
            make(i);
        }
        vector<int> prev={};
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0],v=edges[i][1];
            if(find(u)!=find(v))
            {
                unionSet(u,v);
            }
            else
            {
                prev={u,v};
            }
        }
        return prev;
    }
};