class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,1e9));
        dp[1][1]=grid[0][0];
        for(int i =1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(i==1 && j==1) continue;
                dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        for(int i =0;i<=row;i++)
        {
            for(int j=0;j<=col;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[row][col];
    }
};