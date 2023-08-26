class Solution {
public:
    int dp[1001];
    int getAns(vector<vector<int>>& pairs,int ind)
    {
        if(ind>=pairs.size()-1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int ans=0;
        for(int i=ind+1;i<pairs.size();i++)
        {
            if(pairs[ind][1]<pairs[i][0])
            {
                ans=max(ans,1+getAns(pairs,i));
            }
            else
            {
                ans=max(ans,getAns(pairs,i));
            }
        }
        return dp[ind]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return getAns(pairs,0);
    }
};