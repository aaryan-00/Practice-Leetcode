class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        vector<int> vis(nums.size(),0);
        long long ans=0;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(!vis[ind])
            {
                ans+=val;
                if(ind-1>=0) vis[ind-1]=1;
                if(ind+1<nums.size()) vis[ind+1]=1;
                vis[ind]=1;
            }
        }
        return ans;
    }
};