class Solution {
public:
        int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i]))
            {
                int height=heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width=i;
                else width=i-s.top()-1;
                ans=max(ans,height*width);
            }
            s.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
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
        int ans=0;
        ans=max(ans,largestRectangleArea(mat[0]));
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j])
                {
                    mat[i][j]+=mat[i-1][j];
                }
            }
            ans=max(ans,largestRectangleArea(mat[i]));

        }
        return ans;
    }
};