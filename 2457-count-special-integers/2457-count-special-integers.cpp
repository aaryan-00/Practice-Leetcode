class Solution {
public:
    int dp[11][2][1025];
    int solve(vector<int> &num,int pos,int tight,int mask)
    {
        if(pos==num.size()) return mask!=0;
        if(dp[pos][tight][mask]!=-1) return dp[pos][tight][mask];
        int ans=0;
        int ub=9;
        if(tight) ub=num[pos];
        for(int dig=0;dig<=ub;dig++)
        {
            if(mask & (1<<dig)) continue;
            int newMask;
            if(mask==0 && dig==0) newMask=mask;
            else newMask=mask|(1<<dig);
            ans+=solve(num,pos+1,tight&(dig==ub),newMask);
        }
        return dp[pos][tight][mask]=ans;
    }
    int countSpecialNumbers(int n) {
        vector<int> num;
        while(n>0)
        {
            num.push_back(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return solve(num,0,1,0);
    }
};