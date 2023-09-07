class Solution {
public:
    vector<vector<pair<int,int>>> dp;
    int n,m;
    bool check(int mid,vector<vector<int>>& dungeon,int i,int j)
    {
        if(i==n-1 && j==m-1)
        {
            return (dungeon[i][j]+mid)>0;
        }
        if(i>=n||j>=m||mid+dungeon[i][j]<=0) return false;

        if(dp[i][j].first!=-1 && dp[i][j].first>=mid+dungeon[i][j]) return dp[i][j].second;
        bool ans=false;
        ans=ans||check(mid+dungeon[i][j],dungeon,i+1,j);
        ans=ans||check(mid+dungeon[i][j],dungeon,i,j+1);
        dp[i][j].first = max(dp[i][j].first, mid + dungeon[i][j]);
        return dp[i][j].second=ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int ans=INT_MAX;
        int low=1,high=1e9;
        n=dungeon.size(),m=dungeon[0].size();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            dp=vector<vector<pair<int, int>>>(n , vector<pair<int, int>> (m , {-1,-1}));
            int possible=check(mid,dungeon,0,0);
            if(possible)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};