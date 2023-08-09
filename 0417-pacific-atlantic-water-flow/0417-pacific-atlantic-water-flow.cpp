class Solution {
public:
    
    void dfs(vector<vector<int>> &lake,vector<vector<int>> &mat,int i,int j,int n,int m)
    {
        // vector<int> path={-1,0,1,0,-1};
        // vector<vector<int>> paths{ {0,-1}, {1, 0}, {0, 1}, {-1, 0} };
        // for(int curr=0;curr<4;curr++)
        // {
        //     int nextI=i+paths[curr][0];
        //     int nextJ=j+paths[curr][1];
        //     // cout<<curr<<" "<<curr+1<<endl;
        //     if(nextI<0 || nextI>=n || nextJ<0 || nextJ>=m || lake[nextI][nextJ]==1)
        //     {
        //         continue;
        //     }
        //     if(mat[nextI][nextJ]>=mat[i][j])
        //     {
        //         lake[nextI][nextJ]==1;
        //         dfs(lake,mat,nextI,nextJ);
        //     }
        // }
        int paths[][2] = { {0,-1}, {1, 0}, {0, 1}, {-1, 0} };
        for (int curr = 0; curr < 4; curr++) {
            int nextI = i + paths[curr][0], nextJ = j + paths[curr][1];
            // invalid index or visited
            if (nextI < 0 || nextJ < 0 || nextI >= n || nextJ >= m || lake[nextI][nextJ] == 1) 
            {
                continue;
            }

            if (mat[nextI][nextJ] >=mat[i][j]) {
                lake[nextI][nextJ] = 1; // visited & can flow
                dfs(lake, mat, nextI, nextJ,n,m); 
            } 
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        cout<<n<<m<<endl;
        vector<vector<int>> bluelake(n,vector<int>(m,0));
        vector<vector<int>> redlake(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            bluelake[i][0]=1;
            redlake[i][m-1]=1;
        }
        for(int j=0;j<m;j++)
        {
            bluelake[0][j]=1;
            redlake[n-1][j]=1;
        }
        //   for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (i == 0 || j == 0)
        //             bluelake[i][j] = 1;
        //         if (i == n-1 || j == m-1)
        //             redlake[i][j] = 1;
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bluelake[i][j]==1)
                {
                    dfs(bluelake,mat,i,j,n,m);
                }
                if(redlake[i][j]==1)
                {
                    dfs(redlake,mat,i,j,n,m);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bluelake[i][j]==1 && redlake[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};