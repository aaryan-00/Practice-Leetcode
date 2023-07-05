class Solution {
public:
    int temp;
    void dfs(vector<vector<int>> &adj,vector<bool> &detonated,int src)
    {
        if(detonated[src]) return;
        detonated[src]=true;
        temp++;
        for(auto it:adj[src])
        {
    
            if(!detonated[it])
            {
                dfs(adj,detonated,it);
            }
        }

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long dis=(long)(bombs[i][0]-bombs[j][0])*(bombs[i][0]-bombs[j][0]) + (long)(bombs[i][1]-bombs[j][1])*(bombs[i][1]-bombs[j][1]);
                // cout<<dis<<endl;
                if(dis<=(long)bombs[i][2]*bombs[i][2])
                {
                    adj[i].push_back(j); 
                }
                if(dis<=(long)bombs[j][2]*bombs[j][2])
                {
                    adj[j].push_back(i);
                }  
            }
        }        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<":";
        //     for(auto it:adj[i])
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            temp=0;
            vector<bool> detonated(n);
            dfs(adj,detonated,i);
            ans=max(ans,temp);
        }
        
        return ans;
    }
};