class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void combi(int k,int ind,int target)
    {
        if(target==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<10;i++)
        {
            if(i>target) break;
            temp.push_back(i);
            combi(k,i+1,target-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        temp.clear();
        combi(k,1,n);
        return ans;
    }
};