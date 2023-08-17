class Solution {
public:
    int dp[1001][4];
    int getAns(vector<int>& rating,int ind,int cnt,int prev)
    {
        if(cnt==3) return 1;
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        int ans=0;
        for(int i=ind;i<rating.size();i++)
        {
            if(rating[i]>prev)
            {
                ans+=getAns(rating,i+1,cnt+1,rating[i]);
            }
        }
        return dp[ind][cnt]=ans;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        int res = getAns(rating,0,0,-1);
        reverse(rating.begin(),rating.end());
        memset(dp,-1,sizeof(dp));
        return res+=getAns(rating,0,0,-1);
    }
};