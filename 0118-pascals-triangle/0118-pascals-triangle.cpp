class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> ans;
        ans.push_back(1);
        res.push_back(ans);
        if(numRows==1) return res;
        int i=2;
        while(i<=numRows)
        {
            vector<int> temp(i);
            temp[0]=1,temp[i-1]=1;
            int j=1;
            while(j<ans.size())
            {
                temp[j]=ans[j]+ans[j-1];
                j++;
            }
            ans=temp;
            res.push_back(temp);
            i++;
        }
        return res;
    }
};