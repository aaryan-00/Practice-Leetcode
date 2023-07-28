class Solution {
public:
    int temp=0;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
        {
            return;
        }
        if(grid[i][j])
        {
            grid[i][j]=0;
            temp++;
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    temp=0;
                    dfs(grid,i,j);
                    // cout<<temp<<endl;
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};