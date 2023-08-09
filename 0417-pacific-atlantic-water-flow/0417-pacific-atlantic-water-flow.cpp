class Solution {
public:
    // vector<vector<int>> paths{ {0,-1}, {1, 0}, {0, 1}, {-1, 0} };
    int n,m;
    vector<int> path={-1,0,1,0,-1}; 
    void dfs(vector<vector<int>> &lake,vector<vector<int>> &mat,int i,int j)
    {

         for(int curr=0;curr<4;curr++)
        {
            int nextI=i+path[curr];
            int nextJ=j+path[curr+1];
            if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && lake[nextI][nextJ]==0 && mat[nextI][nextJ]>=mat[i][j])
            {
                lake[nextI][nextJ]=1;
                dfs(lake,mat,nextI,nextJ);
            }
        }
        
        // for(int curr=0;curr<4;curr++)
        // {
        //     int nextI=i+paths[curr][0];
        //     int nextJ=j+paths[curr][1];
        //     if(nextI<0 || nextI>=n || nextJ<0 || nextJ>=m || lake[nextI][nextJ]==1)
        //     {
        //         continue;
        //     }
        //     if(mat[nextI][nextJ]>=mat[i][j])
        //     {
        //         lake[nextI][nextJ]=1;
        //         dfs(lake,mat,nextI,nextJ);
        //     }
        // }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
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
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bluelake[i][j]==1)
                {
                    dfs(bluelake,mat,i,j);
                }
                if(redlake[i][j]==1)
                {
                    dfs(redlake,mat,i,j);
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