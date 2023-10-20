class Solution {
public:
    int m, n;
    int dp[71][5000];
    int solve(vector<vector<int>>& mat, int row, int sum, const int& target)
    {
        if(row == m)
        {
            return abs(sum - target);
        }
        
        if(dp[row][sum] != -1) return dp[row][sum];
        
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, solve(mat, row+1, sum+mat[row][i], target));
            // if(ans==0) break;
        }
        return dp[row][sum] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(mat, 0, 0, target);;
    }
};