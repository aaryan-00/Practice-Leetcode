class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        } 
        vector<int> ans;
        while(!pq.empty() && k>0)
        {
            int curr=pq.top().second;
            pq.pop();
            ans.push_back(curr);
            k--;
        }
        return ans;
    }
};