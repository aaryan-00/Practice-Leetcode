class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && st.top()>nums[i] && (st.size()-1)+(nums.size() - i)>=k)
            {
                st.pop();
            }
            if(st.size()<k)
            {
                st.push(nums[i]);
            }
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};