class Solution {
public:
    int dp[50001][2];
    int getAns(vector<int> &piles,int ind,bool alice)
    {
        int n=piles.size();
        if(ind==n) return 0;
        if(dp[ind][alice]!=-1) return dp[ind][alice];
        if(alice)
        {
            int currSum=0,ans=INT_MIN;
            for(int x=1;x<=min(3,n-ind);x++)
            {
                currSum+=piles[x+ind-1];
                ans=max(ans,currSum+getAns(piles,ind+x,!alice));
            }
            return dp[ind][alice]=ans;

        }
        int currSum=0,ans=INT_MAX;
        for(int x=1;x<=min(3,n-ind);x++)
        {
            currSum+=piles[x+ind-1];
            ans=min(ans,getAns(piles,ind+x,!alice));
        }
        return dp[ind][alice]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int total=0;
        for(auto i:stoneValue)
        {
            total+=i;
        }
        
        int alice= getAns(stoneValue,0,1),bob=total-alice;
        if(alice>bob) return "Alice";
        if(bob>alice) return "Bob";
        return "Tie";
    }
};