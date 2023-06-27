class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        } 
        string ans="";
        while(!pq.empty())
        {
            char c=pq.top().second;
            int cnt=pq.top().first;
            pq.pop();
            // while(cnt--)
            // {
            //     ans+=c;
            // }
            ans.append(cnt,c);
        }
        return ans;
    }
};