class Solution {
public:
    int dp[501][501];
    int LCS(vector<int> &s,vector<int> &t,int i,int j)
    {
        if(i<0||j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j])
        {
            return dp[i][j]=1+LCS(s,t,i-1,j-1);
        }

        return dp[i][j]=max(LCS(s,t,i,j-1),LCS(s,t,i-1,j));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        memset(dp,-1,sizeof(dp));
        return LCS(nums1,nums2,n-1,m-1);
    }
};