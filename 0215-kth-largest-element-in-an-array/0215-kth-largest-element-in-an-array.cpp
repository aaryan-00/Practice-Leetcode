class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        int ans;
        while(!pq.empty() && k>0)
        {
            int curr=pq.top();
            pq.pop();
            if(k==1)
            {
                ans=curr;
            }
            k--;
        }
        return ans;
    }
};