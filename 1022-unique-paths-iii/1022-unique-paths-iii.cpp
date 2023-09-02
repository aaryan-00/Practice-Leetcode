class Solution {
public:
    int n,m;
    int ans=0;
    bool vis[20][20];
    void dfs(int i,int j,vector<vector<int>>& grid,int cost,int cnt)
    {
        if(i<0||j<0||i>=n||j>=m||vis[i][j]||grid[i][j]==-1) return;
        if(grid[i][j]==2)
        {
            if(cost==cnt) ans++;
            return;
        }
        vis[i][j]=true;
        if(grid[i][j]==0)
        {
            cnt++;
        } 
        dfs(i+1,j,grid,cost,cnt);
        dfs(i-1,j,grid,cost,cnt);
        dfs(i,j+1,grid,cost,cnt);
        dfs(i,j-1,grid,cost,cnt);
        vis[i][j]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int stI,stJ;
        int cost=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    stI=i,stJ=j;
                }
                if(grid[i][j]==0)
                {
                    cost++;
                }
            }
        }
        cout<<cost<<endl;
        memset(vis,false,sizeof(vis));
        dfs(stI,stJ,grid,cost,0);
        return ans;
    }
};