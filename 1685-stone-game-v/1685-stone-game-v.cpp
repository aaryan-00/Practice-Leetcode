class Solution {
public:
    int dp[501][501];
    int getAns(vector<int> &stone,int low,int high)
    {
        if(low==high) return 0;
        if(dp[low][high]!=-1) return dp[low][high];
        int total=0;
        for(int i=low;i<=high;i++)
        {
            total+=stone[i];
        }
        int curr=0;
        int ans=INT_MIN;
        for(int i=low;i<=high-1;i++)
        {
            curr+=stone[i];
            int sec=total-curr;
            if(curr<sec)
            {
                ans=max(ans,curr+getAns(stone,low,i));
            }
            else if(curr>sec)
            {
                ans=max(ans,sec+getAns(stone,i+1,high));
            }
            else
            {
                ans=max(ans,curr+getAns(stone,low,i));
                ans=max(ans,sec+getAns(stone,i+1,high));
            }
        }
        return dp[low][high]=ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        return getAns(stoneValue,0,n-1);
    }
};