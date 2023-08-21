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
            if(sizes[b]>sizes[a]) swap(b,a);
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
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind mst(n);
        sort(edgeList.begin(),edgeList.end(),comp);
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        vector<bool> ans(queries.size(),false);
        int j=0;
        for(int i=0;i<queries.size();i++)
        {
            while(j<edgeList.size() && edgeList[j][2]<queries[i][2])
            {
                int u=edgeList[j][0];
                int v=edgeList[j][1];
                if(mst.findParent(u)!=mst.findParent(v))
                {
                    mst.Union(u,v);
                }
                j++;
            }
            
            int u=queries[i][0];
            int v=queries[i][1];
            if(mst.findParent(u)==mst.findParent(v))
            {
                ans[queries[i][3]] = true;
            }
        }
        return ans;
    }
};