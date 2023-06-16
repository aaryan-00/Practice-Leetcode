class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0 && mat[i][j])
                {
                    ans+=mat[i][j];
                }
                else
                {
                    if(mat[i][j])
                    {
                        mat[i][j]+=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]));
                        ans+=mat[i][j];
                    }
                }
            }
        }
        return ans;
    }
};