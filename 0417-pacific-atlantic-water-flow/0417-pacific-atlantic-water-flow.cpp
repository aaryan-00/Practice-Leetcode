class Solution {
public:
    // // vector<vector<int>> paths{ {0,-1}, {1, 0}, {0, 1}, {-1, 0} };
    int n,m;
    vector<int> path={-1,0,1,0,-1}; 
    // void dfs(vector<vector<bool>> &lake,vector<vector<int>> &mat,int i,int j)
    // {

    //      for(int curr=0;curr<4;curr++)
    //     {
    //         int nextI=i+path[curr];
    //         int nextJ=j+path[curr+1];
    //         if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && lake[nextI][nextJ]==0 && mat[nextI][nextJ]>=mat[i][j])
    //         {
    //             lake[nextI][nextJ]=1;
    //             dfs(lake,mat,nextI,nextJ);
    //         }
    //     }
        
    //     // for(int curr=0;curr<4;curr++)
    //     // {
    //     //     int nextI=i+paths[curr][0];
    //     //     int nextJ=j+paths[curr][1];
    //     //     if(nextI<0 || nextI>=n || nextJ<0 || nextJ>=m || lake[nextI][nextJ]==1)
    //     //     {
    //     //         continue;
    //     //     }
    //     //     if(mat[nextI][nextJ]>=mat[i][j])
    //     //     {
    //     //         lake[nextI][nextJ]=1;
    //     //         dfs(lake,mat,nextI,nextJ);
    //     //     }
    //     // }
    // }


    void bfs(vector<vector<bool>> &lake,queue<pair<int,int>> &q,vector<vector<int>>& mat)
    {
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            int i=curr.first;
            int j=curr.second;
            q.pop();
            for(int curr=0;curr<4;curr++)
            {
                int nextI=i+path[curr];
                int nextJ=j+path[curr+1];
                if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && lake[nextI][nextJ]==0 && mat[nextI][nextJ]>=mat[i][j])
                {
                    lake[nextI][nextJ]=1;
                    q.push({nextI,nextJ});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        // cout<<n<<m<<endl;
        vector<vector<bool>> bluelake(n,vector<bool>(m,0));
        vector<vector<bool>> redlake(n,vector<bool>(m,0));
        


        queue<pair<int,int>> blue;
        queue<pair<int,int>> red;
        for(int i=0;i<n;i++)
        {
            bluelake[i][0]=1;
            redlake[i][m-1]=1;
            blue.push({i,0});
            red.push({i,m-1});
        }
        for(int j=0;j<m;j++)
        {
            bluelake[0][j]=1;
            redlake[n-1][j]=1;
            blue.push({0,j});
            red.push({n-1,j});
        }
        bfs(bluelake,blue,mat);
        bfs(redlake,red,mat);

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(bluelake[i][j]==1)
        //         {
        //             dfs(bluelake,mat,i,j);
        //         }
        //         if(redlake[i][j]==1)
        //         {
        //             dfs(redlake,mat,i,j);
        //         }
        //     }
        // }
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