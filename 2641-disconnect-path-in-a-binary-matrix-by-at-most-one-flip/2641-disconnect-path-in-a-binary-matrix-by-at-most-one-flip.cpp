class Solution {
public:
    int n,m;
    bool getCnt(int i,int j,vector<vector<int>>& grid)
    {
        if(i==n-1 && j==m-1) return true;
        if(i>=n ||j>=m||grid[i][j]==0) return false;
        grid[i][j]=0;
        return getCnt(i+1,j,grid)||getCnt(i,j+1,grid);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(getCnt(0,0,grid)==false) return true;
        grid[0][0]=1;
        // return !getCnt(0, 0,grid);
        if(getCnt(0,0,grid)) return false;
        return true;
    }
};