class Solution {
public:
    int ans=0,temp,n,m;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=n||j>=m) return;
        if(grid[i][j]==1)
        {
            temp++;
            grid[i][j]=0;
            for(int k=0;k<m;k++)
            {
                if(grid[i][k])
                {
                    dfs(i,k,grid);
                }
            }            
            for(int k=0;k<n;k++)
            {
                if(grid[k][j])
                {
                    dfs(k,j,grid);
                }
            }   
        }
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    temp=0;
                    dfs(i,j,grid);
                    if(temp>1)ans+=temp;
                }
            }
        }
        return ans;
    }
};