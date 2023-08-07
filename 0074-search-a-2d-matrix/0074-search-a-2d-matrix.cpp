class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int i=0;
    //     for(;i<matrix.size();i++)
    //     {
    //         if(matrix[i][0]>target)
    //         {
    //             break;
    //         }
    //     }
    //     // cout<<i<<endl;
    //     if(i==0) return false;
    //     i--;
    //     int lo=0,hi=matrix[0].size()-1;
    //     while(lo<=hi)
    //     {
    //         int mid=hi+lo>>1;
    //         if(matrix[i][mid]==target) return true;
    //         else if(matrix[i][mid]<target) lo=mid+1;
    //         else hi=mid-1;
    //     }
    //     return false;
    // }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo=0,hi=matrix.size()-1;
        while(lo<=hi)
        {
            int mid= hi+lo >>1;
            if(matrix[mid][0]<=target) lo=mid+1;
            else hi=mid-1;
        }
        cout<<hi<<endl;
        if(hi<0) return false;
        int i=hi;
        lo=0,hi=matrix[0].size()-1;
        while(lo<=hi)
        {
            int mid=hi+lo>>1;
            if(matrix[i][mid]==target) return true;
            else if(matrix[i][mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }

        

};