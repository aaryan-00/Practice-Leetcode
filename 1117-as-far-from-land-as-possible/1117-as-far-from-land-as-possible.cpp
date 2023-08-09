class Solution {
public:
    // vector<int> paths={-1,0,1,0,-1};
    // int maxDistance(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     queue<pair<int,int>> q;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==1) 
    //             {
    //                 q.push({i,j});
    //                 grid[i][j]=0;
    //             }
    //             else
    //             {
    //                 grid[i][j]=-1;
    //             }
    //         }
    //     }
    //     if(q.size()==0 || q.size()==n*m) return -1;
    //     int ans=INT_MIN;
    //     while(!q.empty())
    //     {
    //         pair<int,int> curr=q.front();
    //         q.pop();
    //         int i=curr.first;
    //         int j=curr.second;
    //         for(int curr=0;curr<4;curr++)
    //         {
    //             int nextI=i+paths[curr];
    //             int nextJ=j+paths[curr+1];
    //             if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && grid[nextI][nextJ]==-1)
    //             {
    //                 grid[nextI][nextJ]=grid[i][j]+1;
    //                 ans=max(ans,grid[nextI][nextJ]);
    //                 q.push({nextI,nextJ});
    //             }
    //         }
    //     }
    //     return ans; 
    // }


    vector<int> paths={-1,0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) 
                {
                    q.push({i,j});
                    grid[i][j]=0;
                }
                else
                {
                    grid[i][j]=-1;
                }

            }
        }
        if(q.size()==0 || q.size()==n*m) return -1;
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                for(int curr=0;curr<4;curr++)
                {
                    int nextI=i+paths[curr];
                    int nextJ=j+paths[curr+1];
                    if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && grid[nextI][nextJ]==-1)
                    {
                        grid[nextI][nextJ]=level;
                        q.push({nextI,nextJ});
                    }
                }
            }
            level++;

        }
        return level-1; 
    }
};