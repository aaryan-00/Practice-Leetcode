class unionFind{
public:
    vector<int> par;
    unionFind()
    {
        par.resize(26);
        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int v)
    {
        if(par[v]==v) return v;
        return par[v]=findPar(par[v]);
    }
    void makeUnion(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a!=b)
        {
            if(a<b) 
            {

                par[b]=a;
            }
            else if(a>b)
            {
                par[a]=b;
            }
            
        }
    }
};
class Solution {
public:

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unionFind uf;
        for(int i=0;i<s1.size();i++)
        {
            int a=s1[i]-'a';
            int b=s2[i]-'a';
            if(uf.findPar(a)!=uf.findPar(b))
            {
                uf.makeUnion(a,b);
            }
        }
        for(auto &i:baseStr)
        {
            i=uf.findPar(i-'a')+'a';
        }
        return baseStr;
    }
};