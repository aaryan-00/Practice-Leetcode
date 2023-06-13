class Solution {
public:
    void dfs(int src,vector<vector<int>>& rooms,vector<int> &vis)
    {
        vis[src]=1;
        for(auto i:rooms[src])
        {
            if(vis[i]==0)
            {
                dfs(i,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);
        int sum=accumulate(vis.begin(),vis.end(),0);
        for(auto i:vis)
        {
            cout<<i<<" ";        }
        cout<<sum<<endl;
        if(sum==n)
        {
            return true;
        }
        return false;

    }
};