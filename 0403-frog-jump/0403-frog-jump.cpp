class Solution {
public:
    unordered_map<int,int> mp;
    int dp[2001][2001];
    int getAns(vector<int> &stones,int ind,int k)
    {
        if(ind==stones.size()-1) return true;
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool ans=false;
        for(int i=-1;i<=1;i++)
        {
            int curr=stones[ind]+k+i;
            if(curr>stones[ind] && mp.find(curr)!=mp.end())
            {
                
                int nextIdx=mp[curr];
                ans|=getAns(stones,nextIdx,k+i);
            }
            // cout<<endl;
        }
        return dp[ind][k]=ans;
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i;
        }
        return getAns(stones,0,0);
    }
};