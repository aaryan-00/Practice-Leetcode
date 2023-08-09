class Solution {
public:
    // vector<int> paths={-1,0,1,0,-1};
    // vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    //     int n=isWater.size();
    //     int m=isWater[0].size();
    //     queue<pair<int,int>> q;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(isWater[i][j]==1) q.push({i,j});
    //         }
    //     }
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
    //             if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && isWater[nextI][nextJ]==0)
    //             {
    //                 isWater[nextI][nextJ]=isWater[i][j]+1;
    //                 q.push({nextI,nextJ});
    //             }
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             isWater[i][j]--;
    //         }
    //     }
    //     return isWater;  
    // }


    vector<int> paths={-1,0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1) 
                {
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else
                {
                    isWater[i][j]=-1;
                }

            }
        }
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;
            for(int curr=0;curr<4;curr++)
            {
                int nextI=i+paths[curr];
                int nextJ=j+paths[curr+1];
                if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && isWater[nextI][nextJ]==-1)
                {
                    isWater[nextI][nextJ]=isWater[i][j]+1;
                    q.push({nextI,nextJ});
                }
            }

        }
        return isWater;  
    }
};