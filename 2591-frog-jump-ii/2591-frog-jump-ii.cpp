class Solution {
public:
    bool check(vector<int> &stones,int mid)
    {
        int n = stones.size();
        vector<bool> vis(n, false);
        
        int i = 1, cur = 0, prev = 0;
        while (i < n) {
            if ((stones[i] - stones[cur]) > mid) {
                if (prev != cur && !vis[prev]) {
                    cur = prev;
                    vis[prev] = true;
                } else {
                    return false;
                }
            } else {
                prev = i++;
            }
        }
        
        cur = 0; prev = 0; i = 1;
        while (i < n) {
            if (vis[i]) {
                ++i; continue;
            }
            if ((stones[i] - stones[cur]) > mid) {
                if (prev != cur) {
                    cur = prev;
                } else {
                    return false;
                }
            } else {
                prev = i++;
            }
        }
        
        return true;
    }
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int low=0,high=1e9;
        int ans=stones[n-1]-stones[0];
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(check(stones,mid))
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

    // int maxJump(vector<int>& stones) {
    //     int res, n = stones.size();
    //     res = stones[1] - stones[0];
    //     for (int i = 2; i < n; i++) {
    //         res = max(res, stones[i] - stones[i - 2]);
    //     }
    //     return res;
    // }
};