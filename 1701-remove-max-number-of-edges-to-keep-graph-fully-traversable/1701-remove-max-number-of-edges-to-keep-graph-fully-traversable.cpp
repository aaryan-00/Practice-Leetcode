class UnionFind{
public:
    vector<int> parent,sizes;
    UnionFind(int n)
    {
        parent.resize(n);
        sizes.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            sizes[i]=1;
        }
    }
    int findParent(int v)
    {
        if(parent[v]==v) return v;
        return parent[v]=findParent(parent[v]);
    }
    void Union(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
        if(a!=b)
        {
            parent[b]=a;
            sizes[a]+=sizes[b];
        }
    }
    int maxSize()
    {
        int cnt=0;
        for(auto i:sizes)
        {
            cnt=max(cnt,i);
        }
        return cnt;
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n),bob(n);
        sort(edges.begin(),edges.end(),comp);
        int ans=0;
        for(auto i:edges)
        {
            int type=i[0];
            int u=i[1]-1;
            int v=i[2]-1;
            if(type==3)
            {
                if(alice.findParent(u)!=alice.findParent(v))
                {
                    alice.Union(u,v);
                    bob.Union(u,v);
                }
                else
                {
                    ans++;
                }
            }
            else if(type==2)
            {
                if(alice.findParent(u)!=alice.findParent(v))
                {
                    alice.Union(u,v);
                }
                else ans++;
            }
            else
            {
                if(bob.findParent(u)!=bob.findParent(v))
                {
                    bob.Union(u,v);
                }
                else ans++;
            }
        }
        if(alice.maxSize()!=n||bob.maxSize()!=n) return -1;
        return ans;
    }
};