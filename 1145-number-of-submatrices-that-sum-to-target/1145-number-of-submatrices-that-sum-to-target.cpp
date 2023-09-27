class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        preSum[0][0]=matrix[0][0];
        for(int i=1;i<n;i++)
        {
            preSum[i][0]=preSum[i-1][0]+matrix[i][0];
        }
        for(int j=1;j<m;j++)
        {
            preSum[0][j]=preSum[0][j-1]+matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                preSum[i][j]=matrix[i][j]+preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1];
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<preSum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int i0=i;i0<n;i0++)
                {
                    for(int j0=j;j0<m;j0++)
                    {
                        int currSum=preSum[i0][j0];
                        if(i>0)currSum-=preSum[i-1][j0];
                        if(j>0)currSum-=preSum[i0][j-1];
                        if(i>0 && j>0)currSum+=preSum[i-1][j-1];
                        if(currSum==target) ans++;
                    }
                }
            }
        }

        return ans;
    }
};