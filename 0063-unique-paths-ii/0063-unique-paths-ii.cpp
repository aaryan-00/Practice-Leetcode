#define ll long long
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    ll paths(ll i,ll j,vvi &v,vvi &dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(v[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];    
        }
        ll left=paths(i-1,j,v,dp);
        ll up=paths(i,j-1,v,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ll m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }
        vvi dp(m,vi(n,-1));
        return paths(m-1,n-1,obstacleGrid,dp);
    }
};