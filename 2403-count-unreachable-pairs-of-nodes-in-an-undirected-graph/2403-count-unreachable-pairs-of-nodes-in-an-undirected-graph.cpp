class Solution {
public:
    vector<int> par;
    vector<int> sizes;
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
    void setUnion(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sizes[b] > sizes[a])
            {
                swap(b, a);
            }
            // if(b<a)
            // {
            //     swap(a,b);
            // }
            par[b] = a;
            sizes[a] += sizes[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        sizes.resize(n);
        for(int i=0;i<n;i++)
        {
            make(i);
        }
        for(auto i: edges)
        {
            setUnion(i[0],i[1]);
        }
        for(auto i:par)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:sizes)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
        // set<int> parents;
        // long long tot_sz=n;
        // long long ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     int curr_par=find(i);
        //     if(parents.count(curr_par)==0)
        //     {
        //         long long curr_sz=sizes[i];
        //         tot_sz-=curr_sz;
        //         ans+=curr_sz*tot_sz;
        //         parents.insert(curr_par);
        //     }
        // }
        long long current=0;
        long long ans=0;
        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                if(sizes[i] == n) {
                    return 0;
                }
                    ans += current * (int)sizes[i];
                    current += (int)sizes[i];
            }
        }
        return ans;
    }
};