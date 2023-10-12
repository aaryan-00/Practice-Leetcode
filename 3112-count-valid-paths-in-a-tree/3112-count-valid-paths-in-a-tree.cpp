class Solution {
public:
class UnionFind {
public: 
    vector<int> parent; 
    vector<int> sizes;
    UnionFind(int n){
        parent.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<=n;i++)
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
};
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> is_prime(n+1,true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    is_prime[i] = false;
                }
            }
        }

        UnionFind uf(n);
        vector<int> adj[n+1];
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            if(is_prime[e[0]]||is_prime[e[1]]) continue;

            uf.Union(e[0],e[1]);
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(is_prime[i]==false) continue;
            vector<long long> childSize;
            for(auto &it:adj[i])
            {
                if(is_prime[it]) continue;
                int par=uf.findParent(it);
                childSize.push_back(uf.sizes[par]);
            }
            long long sum=accumulate(childSize.begin(),childSize.end(),1);
            for(auto& c:childSize){
                sum-=c;
                ans+=sum*c;
            }
        }
        return ans;

    }
};