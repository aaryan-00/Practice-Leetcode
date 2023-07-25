class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // set<int> s;
        // for(int i=0;i<nums.size();i++)
        // {
        //     s.insert(nums[i]);
        // }
        // return s.size()!=nums.size();
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==nums[i-1]) return true;
        }
        return false;

    }
};