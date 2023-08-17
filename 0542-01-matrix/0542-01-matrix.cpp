#define ll long long
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        vector<int> diff={-1,0,1,0,-1};
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> curr=q.front();
                q.pop();
                ll curr_r=curr.first;
                ll curr_c=curr.second;
                for(int j=0;j<4;j++)
                {
                    ll row=curr_r+diff[j];
                    ll col=curr_c+diff[j+1];
                    if(row>=0 && row<n && col>=0 && col<m && mat[row][col]==-1)
                    {
                        mat[row][col]=1+mat[curr_r][curr_c];
                        q.push({row,col});
                    }
                }
            }
        }
        return mat;
    }
};