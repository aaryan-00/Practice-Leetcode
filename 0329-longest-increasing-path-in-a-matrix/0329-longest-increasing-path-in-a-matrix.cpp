class Solution {
public:
    int dp[201][201];
    vector<int> path={-1,0,1,0,-1};
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& matrix)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        // vis[i][j]=true;
        for(int it=0;it<4;it++)
        {
            int newI=i+path[it],newJ=j+path[it+1];
            if(newI>=0&&newJ>=0&&newI<n&&newJ<m&&matrix[newI][newJ]>matrix[i][j])
            {
               ans=max(ans,1+dfs(newI,newJ,matrix)); 
            }
        }
        // vis[i][j]=false;
        return dp[i][j]=ans;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // vector<vector<bool>> vis(n,vector<bool>(m,false));
                int curr=dfs(i,j,matrix);
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};