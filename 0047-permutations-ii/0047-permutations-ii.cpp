class Solution {
public:
    // int n;
    // vector<int> temp;
    // set<vector<int>> ans;
    // vector<bool> vis;
    // void getAns(vector<int>& nums)
    // {
    //     if(temp.size()==n)
    //     {
    //         ans.insert(temp);
    //         return;
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         if(vis[i]==false)
    //         {
    //             vis[i]=true;
    //             temp.push_back(nums[i]);
    //             getAns(nums);
    //             vis[i]=false;
    //             temp.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     n=nums.size();
    //     vis.resize(n,false);
    //     temp.clear();
    //     getAns(nums);
    //     vector<vector<int>> res;
    //     for(auto i:ans)
    //     {
    //         res.push_back(i);
    //     }
    //     return res;
    // }



  public:
    //without extra space 
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for (int i = index; i < nums.size(); i++) 
        {
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector < vector < int >> permuteUnique(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};