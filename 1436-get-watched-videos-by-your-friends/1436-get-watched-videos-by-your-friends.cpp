class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        vector<int> dis(n,-1);
        queue<int> q;
        q.push(id);
        dis[id]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            // cout<<node<<endl;
            for(auto it:friends[node])
            {
                if(dis[it]==-1)
                {
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            if(dis[i]==level)
            {
                vector<string> curr=watchedVideos[i];
                for(auto it:curr)
                {
                    mp[it]++;   
                }
            }
        }
        set<pair<int,string>> temp;
        for(auto i:mp)
        {
            temp.insert({i.second,i.first});
        }
        vector<string> ans;
        for(auto i:temp)
        {
            ans.push_back(i.second);
        }
        return ans;


    }
};