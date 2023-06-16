class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int maxi=0;
        vector<vector<int>> mat(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0 && mat[i][j])
                {
                    maxi=max(maxi,mat[i][j]);;
                }
                else
                {
                    if(mat[i][j])
                    {
                        mat[i][j]+=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]));
                        maxi=max(maxi,mat[i][j]);
                    }
                }
            }
        }
        cout<<maxi<<endl;
        return maxi*maxi;
    }
};