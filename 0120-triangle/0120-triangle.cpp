class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=-1;
        for(int i=0;i<row;i++)
        {
            int curr=triangle[i].size();
            col=max(col,curr);
        }
        vector<vector<int>> grid(row,vector<int>(col,1e9));
        for(int i=0;i<row;i++)
        {
            int curr=triangle[i].size();
            for(int j=0;j<curr;j++)
            {
                grid[i][j]=triangle[i][j];
            }
        }
        vector<vector<int>> dp(row+1,vector<int>(col+1,1e9));
        dp[1][1]=grid[0][0];
        for(int i =1;i<=row;i++)
        {
            int curr=triangle[i-1].size();
            for(int j=1;j<=curr;j++)
            {
                if(i==1 && j==1) continue;
                dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        int ans=1e9;
        for(int i=1;i<=col;i++)
        {
            ans=min(ans,dp[row][i]);
        }
        return ans;
    }
};