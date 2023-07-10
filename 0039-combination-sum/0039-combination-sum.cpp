class Solution {
public:
    void combi(vector<int>& candidates,int target,int ind,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            temp.push_back(candidates[ind]);
            combi(candidates,target-candidates[ind],ind,ans,temp);
            temp.pop_back();
        }
        combi(candidates,target,ind+1,ans,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combi(candidates,target,0,ans,temp);
        return ans;
    }
};