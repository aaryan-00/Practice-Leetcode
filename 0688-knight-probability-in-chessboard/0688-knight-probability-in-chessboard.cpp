class Solution {
public:
    // vector<vector<vector<double>>> dp;
    // double dp[101][26][26];
    vector<vector<int>> directions={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    // double memo(int n,int k,int i,int j)
    // {
    //     if(i<0||j<0||i>=n||j>=n) return 0;
    //     if(k==0) return 1;
    //     if(dp[k][i][j]!=0) return dp[k][i][j];
    //     double total=0;
    //     for(int pos=0;pos<moves.size();pos++)
    //     {
    //         total+=memo(n,k-1,i+directions[pos][0],j+directions[pos][1])/8;
    //     }
    //     // total/=8;
    //     return dp[k][i][j]=total;
    // }
    // double knightProbability(int n, int k, int row, int col) {
    //     // dp.resize(k+1,vector<vector<double>>(n,vector<double>(n,0.0)));
    //     // vector dp(k + 1, vector (n, vector<double>(n, 0.0)));
    //     return memo(n,k,row,col);
    // }

// 3d tabulation
    // double knightProbability(int n, int k, int row, int col) {
    //     vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,0.0)));
    //     dp[0][row][col]=1;
    //     for(int moves=1;moves<=k;moves++)
    //     {
    //         for(int i=0;i<n;i++)
    //         {
    //             for(int j=0;j<n;j++)
    //             {
    //                 for(auto &curr:directions)
    //                 {
    //                     int r=i+curr[0];
    //                     int c=j+curr[1];
    //                     if(r>=0 && r<n && c>=0 && c<n)
    //                     {
    //                         dp[moves][i][j]+= dp[moves-1][r][c]/8;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     double ans=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             ans+=dp[k][i][j];
    //         }
    //     }
    //     return ans;
    // }

// 2d tabulation
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>> dp(n,vector<double>(n,0));
        dp[row][col]=1;
        for(int moves=1;moves<=k;moves++)
        {
            vector<vector<double>> currdp(n,vector<double>(n,0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(auto &curr:directions)
                    {
                        int r=i+curr[0];
                        int c=j+curr[1];
                        if(r>=0 && r<n && c>=0 && c<n)
                        {
                            currdp[i][j]+= dp[r][c]/8;
                        }
                    }
                }
            }
            dp=currdp;
        }
        double ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=dp[i][j];
            }
        }
        return ans;
        

    }
};