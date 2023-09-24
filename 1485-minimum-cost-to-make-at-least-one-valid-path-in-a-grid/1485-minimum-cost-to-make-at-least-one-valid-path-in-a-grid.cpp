class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        bool st=false;
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};
        unordered_map<int,pair<int,int>> mp;
        mp[1]={0,1};
        mp[2]={0,-1};
        mp[3]={1,0};
        mp[4]={-1,0};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        while(!pq.empty())
        {
            pair<int,pair<int,int>> curr=pq.top();
            pq.pop();
            int cnt=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            if(vis[i][j]) continue;
            vis[i][j]=true;
            cout<<cnt<<endl;
            if(i==n-1 && j==m-1) return cnt;
            for(int it=0;it<=3;it++)
            {
                int newi=i+dx[it],newj=j+dy[it];
                if(newi==0 && newj==0) continue;
                if(newi>=0 && newj>=0 && newi<n && newj<m && vis[newi][newj]==false)
                {
                    pair<int,int> dir=mp[grid[i][j]];
                    if(dir.first==dx[it] && dir.second==dy[it])
                    {
                        pq.push({cnt,{newi,newj}});
                    }
                    else
                    {
                        pq.push({cnt+1,{newi,newj}});
                    }
                }
            }   
        }
        return 0;
    }
};