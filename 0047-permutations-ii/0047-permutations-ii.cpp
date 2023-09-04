class Solution {
public:
    int n;
    vector<int> temp;
    set<vector<int>> ans;
    vector<bool> vis;
    void getAns(vector<int>& nums)
    {
        if(temp.size()==n)
        {
            ans.insert(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                temp.push_back(nums[i]);
                getAns(nums);
                vis[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vis.resize(n,false);
        temp.clear();
        getAns(nums);
        vector<vector<int>> res;
        for(auto i:ans)
        {
            res.push_back(i);
        }
        return res;
    }
};