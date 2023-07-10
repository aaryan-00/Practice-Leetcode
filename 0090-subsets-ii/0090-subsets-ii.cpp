class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void combi(vector<int>& num,int ind)
    {
        ans.push_back(temp);
        for(int i=ind;i<num.size();i++)
        {

            if(i>ind && num[i]==num[i-1])continue;
            temp.push_back(num[i]);
            combi(num,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.clear();
        temp.clear();
        combi(nums,0);
        return ans;
    }
};