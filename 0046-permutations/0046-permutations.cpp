class Solution {
public:
  // TC=n!*n

    // vector<vector<int>>ans;
    // void getPerm(vector<int>& nums,vector<int> &curr)
    // {
    //     if(curr.size()==nums.size())
    //     {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     for(auto &i:nums)
    //     {
    //         if(find(curr.begin(), curr.end(), i) == curr.end())
    //         {
    //             curr.push_back(i);
    //             getPerm(nums,curr);
    //             curr.pop_back();
    //         }
    //     }

    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     ans.clear();
    //     vector<int> curr;
    //     getPerm(nums,curr);
    //     return ans;
    // }

    // vector<vector<int>>ans;
    // vector<int> curr;
    // void getPerm(vector<int>& nums)
    // {
    //     if(curr.size()==nums.size())
    //     {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     for(auto &i:nums)
    //     {
    //         if(find(curr.begin(), curr.end(), i) == curr.end())
    //         {
    //             curr.push_back(i);
    //             getPerm(nums);
    //             curr.pop_back();
    //         }
    //     }

    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     ans.clear();
    //     curr.clear();
    //     getPerm(nums);
    //     return ans;
    // }

//without extra space 
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }
};