class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &check,int i,int j)
    {
        if(i<0||j<0||i==grid1.size() || j==grid1[0].size()||grid2[i][j]==0) return;
        if(grid1[i][j]!=1) 
        {
            check=false;
        }
        grid2[i][j]=0;
        dfs(grid1,grid2,check,i+1,j);
        dfs(grid1,grid2,check,i-1,j);
        dfs(grid1,grid2,check,i,j+1);
        dfs(grid1,grid2,check,i,j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    bool check=true;
                    // cout<<i<<" "<<j<<" ";
                    dfs(grid1,grid2,check,i,j);
                    // cout<<check<<endl;
                    ans+=check;
                }
                
            }
        }
        return ans;

    }
};