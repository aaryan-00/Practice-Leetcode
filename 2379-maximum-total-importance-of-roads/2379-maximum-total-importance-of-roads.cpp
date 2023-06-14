class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n);
        for(auto i:roads)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        sort(indegree.begin(),indegree.end(),greater<int>());
        long long ans=0;
        long long iter=n;
        for(auto i:indegree)
        {
            ans+=(iter*i);
            iter--;
        }
        return ans;
    }
};