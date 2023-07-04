class Solution {
public:
    vector<int> par;
    // vector<int> sizes;
    void make(int v)
    {
        par[v] = v;
        // sizes[v] = 1;
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
            // if (sizes[b] > sizes[a])
            // {
            //     swap(b, a);
            // }
            par[b] = a;
            // sizes[a] += sizes[b];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        // sizes.resize(26);
        for(int i=0;i<26;i++)
        {
            make(i);
        }
        vector<string> equals;
        vector<string> unequals;
        for(auto i:equations)
        {
            if(i[1]=='=') equals.push_back(i);
            else unequals.push_back(i);
        }
        for(auto i:equals)
        {
            int a=i[0]-'a',b=i[3]-'a';
            unionSet(a,b);
        }
        for(auto i:unequals)
        {
            int a=i[0]-'a',b=i[3]-'a';
            int par_a=find(a);
            int par_b=find(b);
            if(par_a==par_b) return false;
        }
        return true;
    }
};