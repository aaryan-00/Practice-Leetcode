class Solution {
public:
    int getInd(vector<vector<int>>& mat, int mid)
    {
        int maxi=-1,ind;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][mid]>maxi)
            {
                maxi=mat[i][mid];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0,high=mat[0].size();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int ind=getInd(mat,mid);
            int left=-1;
            if(mid!=0) left=mat[ind][mid-1];
            int right=-1;
            if(mid!=mat[0].size()-1) right=mat[ind][mid+1];

            if(mat[ind][mid]>left && mat[ind][mid]>right)
            {
                return {ind,mid};
            }
            else if(mat[ind][mid]>left) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};