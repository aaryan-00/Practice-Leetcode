class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        for(int i =0;i<row;i++)
        {
            int curr=triangle[i].size();
            for(int j=0;j<curr;j++)
            {
                if(i==0 && j==0) continue;
                if(i==j)
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }
                else if(j==0 && i!=0)
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                else
                {
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        for(int i =0;i<row;i++)
        {
            int curr=triangle[i].size();
            for(int j=0;j<curr;j++)
            {
                cout<<triangle[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=1e9;
        for(int i=0;i<triangle[row-1].size();i++)
        {
            ans=min(ans,triangle[row-1][i]);
        }
        return ans;
        
    }
};