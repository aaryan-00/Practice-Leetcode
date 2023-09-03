class Solution {
public:
    int ans=0,n,m;
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0) return 0;
        int temp=grid[i][j];
        grid[i][j]=0;
        return temp+dfs(i+1,j,grid)+ dfs(i-1,j,grid)+dfs(i,j+1,grid)+dfs(i,j-1,grid);             
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    int curr=dfs(i,j,grid);
                    cout<<curr<<endl;
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};