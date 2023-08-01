class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void getCombi(int ind,int n,int k)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=n;i++)
        {
            temp.push_back(i);
            getCombi(i+1,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        temp.clear();
        getCombi(1,n,k);
        return ans;
    }
};