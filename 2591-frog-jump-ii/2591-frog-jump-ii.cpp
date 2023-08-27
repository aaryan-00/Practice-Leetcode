class Solution {
public:
    // bool check(vector<int> &stones,int mid)
    // {
    //     vector<bool> vis(stones.size(),false);
    //     int curr=0,prev=0;
    //     for(int i=0;i<stones.size()-1;i++)
    //     {
    //         curr+=stones[i+1]-stones[i];
    //         if(curr>mid)
    //         {
    //             // if()
    //             vis[i]=true;
    //             curr=stones[i+1]-stones[i];
    //         }
    //     }
    // }
    // int maxJump(vector<int>& stones) {
    //     int n=stones.size();
    //     int low=1,high=stones[n-1];
    //     int ans=high;
    //     while(low<high)
    //     {
    //         int mid=(low+high)>>1;
    //         if(check(stones,mid))
    //         {
    //             ans=min(ans,mid);
    //             high=mid-1;
    //         }
    //         else
    //         {
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }

    int maxJump(vector<int>& stones) {
        int res, n = stones.size();
        res = stones[1] - stones[0];
        for (int i = 2; i < n; i++) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};