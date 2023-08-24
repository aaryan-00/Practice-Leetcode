class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums)
        {
            if(i<=0) continue;
            s.insert(i);
        }
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<=0) return 1;
        for(int i=1;i<=maxi;i++)
        {
            if(s.count(i)==0) return i;
        }
        return maxi+1;
    }
};