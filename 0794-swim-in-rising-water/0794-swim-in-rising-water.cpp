class Solution {
public:
    bool isValid(vector<vector<int>> &heights, int efforts)
    {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int,int>> q;
        if(heights[0][0]>efforts) return false;
        q.push({0, 0});
        vis[0][0]=1;
        vector< int> v = {-1, 0, 1, 0, -1};
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int cur_row = curr.first, cur_col = curr.second;
            if(cur_row==row-1 && cur_col==col-1)
            {
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int new_row = v[i] + cur_row, new_col = v[i+1] + cur_col;
                if ((new_row < row && new_row >= 0) && (new_col < col && new_col >= 0) && vis[new_row][new_col]==0)
                {
                    if (heights[new_row][new_col] <= efforts)
                    {
                        vis[new_row][new_col]=1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int lo=0,hi=n*n;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            if((isValid(grid,mid)))
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return lo;
    }
};