class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hashh;
        for(auto i:s)
        {
            hashh[i]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:hashh)
        {
            pq.push({i.second,i.first});
        }
        string ans=""; 
        while(!pq.empty())
        {
            if(pq.size()==1)
            {
                if(pq.top().first>1) return "";
                else
                {
                    ans+=pq.top().second;
                    pq.pop();
                }
            }
            else
            {
                auto [freq1, char1] = pq.top(); pq.pop();
                auto [freq2, char2] = pq.top(); pq.pop();
                ans += char1;
                ans += char2;
                freq1--,freq2--;
                if (freq1 > 0) pq.push({freq1, char1});
                if (freq2 > 0) pq.push({freq2, char2});
            }
        }
        
        return ans;
    }
};