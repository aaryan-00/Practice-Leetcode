class Solution {
public:
    int dp[101][101][2];
    int getAns(vector<int> &piles,int m,int ind,bool alice)
    {
        int n=piles.size();
        if(ind==n) return 0;
        if(dp[ind][m][alice]!=-1) return dp[ind][m][alice];
        if(alice)
        {
            int currSum=0,ans=INT_MIN;
            for(int x=1;x<=min(2*m,n-ind);x++)
            {
                currSum+=piles[x+ind-1];
                ans=max(ans,currSum+getAns(piles,max(x,m),ind+x,!alice));
            }
            return dp[ind][m][alice]=ans;

        }
        int currSum=0,ans=INT_MAX;
        for(int x=1;x<=min(2*m,n-ind);x++)
        {
            currSum+=piles[x+ind-1];
            ans=min(ans,getAns(piles,max(x,m),ind+x,!alice));
        }
        return dp[ind][m][alice]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int total=0;
        for(auto i:piles)
        {
            total+=i;
        }
        memset(dp,-1,sizeof(dp));
        return getAns(piles,1,0,1);
    }
};