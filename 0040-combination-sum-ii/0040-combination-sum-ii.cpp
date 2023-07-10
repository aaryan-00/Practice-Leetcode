class Solution {
public:
    void combi(vector<int>& candidates,int target,int ind,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            combi(candidates,target-candidates[i],i+1,ans,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combi(candidates,target,0,ans,temp);
        return ans;
    }
};