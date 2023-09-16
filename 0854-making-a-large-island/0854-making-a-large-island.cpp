class Solution {
public:
    class Unionfind{
    public:
        vector<int> par;
        vector<int> sizes;
        Unionfind(int n)
        {
            par.resize(n);
            sizes.resize(n);
            for(int i=0;i<n;i++)
            {
                par[i]=i;
                sizes[i]=1;
            }
        }
        int findPar(int v)
        {
            if(par[v]==v) return par[v];
            return par[v]=findPar(par[v]);
        }
        void makeunion(int a,int b)
        {
            a=findPar(a);
            b=findPar(b);
            if(a!=b)
            {
                if(sizes[b]>sizes[a]) swap(b,a);
                par[b]=a;
                sizes[a]+=sizes[b];
            }
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Unionfind dsu(n*n);
        vector<pair<int,int>> zeros;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int node=i*n+j;
                int a=dsu.findPar(node);
                if(grid[i][j]==0)
                {
                    zeros.push_back({i,j});
                    continue;
                }
                if(i+1<n && grid[i+1][j])
                {
                    int newnode=(i+1)*n+j;
                    int b=dsu.findPar(newnode);
                    if(a!=b)
                    {
                        dsu.makeunion(node,newnode);
                    }
                }
                if(j+1<n && grid[i][j+1])
                {
                    int newnode=i*n+j+1;
                    int b=dsu.findPar(newnode);
                    if(a!=b)
                    {
                        dsu.makeunion(node,newnode);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*n;i++)
        {
            ans=max(ans,dsu.sizes[i]);
        }
        vector<int> v={-1,0,1,0,-1};
        // cout<<zeros.size()<<endl;
        for(auto node:zeros)
        {
            int i=node.first,j=node.second;
            unordered_set<int> s;
            for(int iter=0;iter<4;iter++)
            {
                int newi=i+v[iter],newj=j+v[iter+1];
                if(newi>=0 && newi<n && newj>=0 && newj<n && grid[newi][newj]==1)
                {
                    int temp=newi*n+newj;
                    s.insert(dsu.findPar(temp));
                }
            }
            // cout<<s.size()<<endl;
            int curr=1;
            for(auto i:s)
            {
                curr+=dsu.sizes[i];
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};