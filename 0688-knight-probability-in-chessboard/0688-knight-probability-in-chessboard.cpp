class Solution {
public:
    // vector<vector<vector<double>>> dp;
    double dp[101][26][26];
    vector<vector<int>> moves={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    double memo(int n,int k,int i,int j)
    {
        if(i<0||j<0||i>=n||j>=n) return 0;
        if(k==0) return 1;
        if(dp[k][i][j]!=0) return dp[k][i][j];
        double total=0;
        for(int pos=0;pos<moves.size();pos++)
        {
            total+=memo(n,k-1,i+moves[pos][0],j+moves[pos][1])/8;
        }
        // total/=8;
        return dp[k][i][j]=total;
    }
    double knightProbability(int n, int k, int row, int col) {
        // dp.resize(k+1,vector<vector<double>>(n,vector<double>(n,0.0)));
        // vector dp(k + 1, vector (n, vector<double>(n, 0.0)));
        return memo(n,k,row,col);


    }
};