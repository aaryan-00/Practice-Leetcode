class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     stack<pair<int,int>> st;
    //     vector<int> ans(nums.size(),-1);
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         while(!st.empty() && st.top().first < nums[i])
    //         {
    //             ans[st.top().second]=nums[i];
    //             st.pop();
    //         }
    //         st.push({nums[i],i});
    //     }
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         while(!st.empty() && st.top().first < nums[i] && st.top().second!=i)
    //         {
    //             // if(st.top().second!=i)
    //             ans[st.top().second]=nums[i];
    //             st.pop();
    //         }
    //         st.push({nums[i],i});
    //     }
    //     return ans;
    // }

    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<2*nums.size();i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i%nums.size()])
            {
                ans[st.top()]=nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
        }
        return ans;

    }
};