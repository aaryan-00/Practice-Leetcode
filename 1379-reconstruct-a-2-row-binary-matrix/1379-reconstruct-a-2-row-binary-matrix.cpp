class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        int total=0;
        int mini=0;
        for(auto &i:colsum)
        {
            total+=i;
            if(i==2)mini++;
        }
        if(total!=upper+lower || mini>min(upper,lower)) return {};
        vector<vector<int>> ans(2,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            if(colsum[i]==2)
            {
                ans[0][i]=1;
                ans[1][i]=1;
                upper--;
                lower--;
            }
            else if(colsum[i]==0)
            {
                ans[0][i]=0;
                ans[1][i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(colsum[i]==1)
            {
                if(upper>0)
                {
                    ans[0][i]=1;
                    ans[1][i]=0;
                    upper--;
                }
                else
                {
                    ans[0][i]=0;
                    ans[1][i]=1;
                    lower--;
                }
            }   
        }
        return ans;

    }
};