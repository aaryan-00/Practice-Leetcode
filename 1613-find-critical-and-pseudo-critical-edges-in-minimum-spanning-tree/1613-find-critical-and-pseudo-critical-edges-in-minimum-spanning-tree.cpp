class UnionFind {
public: 
    vector<int> parent; 
    vector<int> sizes;
    UnionFind(int n){
        parent.resize(n);
        sizes.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i; 
            sizes[i]=1;
        }
    }
    int findParent(int v) {
        if(parent[v]==v) return v;
        return parent[v]=findParent(parent[v]);
    }
    void Union(int a , int b) {
        a=findParent(a);
        b=findParent(b);
        if(a!=b)
        {
            if(sizes[b]>sizes[a])
            {
                swap(b,a);
            }
            parent[b]=a;
            sizes[a]+=sizes[b];
        }
    }  
    int maxSize()
    {
        int maxi=0;
        for(auto i:sizes)
        {
            maxi=max(i,maxi);
        }
        return maxi;
    }  
};

class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        vector<int> critical,ps_critical;
        sort(edges.begin(),edges.end(),comp);

        int minWeight=0;
        UnionFind ufMini(n);
        for(auto &edge:edges)
        {
            int u=edge[0],v=edge[1],wt=edge[2];
            if(ufMini.findParent(u)!=ufMini.findParent(v))
            {
                ufMini.Union(u,v);
                minWeight+=wt;
            }
        }
        for(int i=0;i<m;i++)
        {
            UnionFind ufIgnore(n);
            int IgnoreWeight=0;
            for(int j=0;j<m;j++)
            {
                if(j==i)continue;
                int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
                if(ufIgnore.findParent(u)!=ufIgnore.findParent(v))
                {
                    ufIgnore.Union(u,v);
                    IgnoreWeight+=wt;
                }
            }
            int totalNodes=ufIgnore.maxSize();
            // cout<<totalNodes<<endl;
            if(totalNodes<n || IgnoreWeight>minWeight)
            {
                critical.push_back(edges[i][3]);
            }
            else
            {
                UnionFind ufInclude(n);
                ufInclude.Union(edges[i][0], edges[i][1]);
                int IncludedWeight = edges[i][2];
                for(int j=0;j<m;j++)
                {
                    if(j==i)continue;
                    int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
                    if(ufInclude.findParent(u)!=ufInclude.findParent(v))
                    {
                        ufInclude.Union(u,v);
                        IncludedWeight+=wt;
                    }
                }
                if(IncludedWeight==minWeight)
                {
                    ps_critical.push_back(edges[i][3]);
                }
            }
        }
        return {critical,ps_critical};

    }
};