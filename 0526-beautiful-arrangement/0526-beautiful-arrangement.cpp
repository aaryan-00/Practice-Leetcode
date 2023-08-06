class Solution {
public:
    int getCnt(int n,int ind,vector<bool> &vis)
    {
        if(ind>n) return 1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false && (i%ind==0 || ind%i==0))
            {
                vis[i]=true;
                ans+=getCnt(n,ind+1,vis);
                vis[i]=false;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<bool> vis(n+1,false);
        return getCnt(n,1,vis);
    }
};