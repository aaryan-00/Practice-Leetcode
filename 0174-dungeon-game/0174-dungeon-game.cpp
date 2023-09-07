class Solution {
public:
    vector<vector<pair<int, int>>> dp;
    bool reach(int i, int j, vector<vector<int>> &arr, int mid){
        if(i == arr.size() - 1 && j == arr[0].size() - 1) {
            return (mid + arr[i][j] > 0); 
        }
        if(i >= arr.size() || j >= arr[0].size() || mid + arr[i][j] <= 0) {   
            return false;
        }
        if(dp[i][j].first != -1 && dp[i][j].first > mid + arr[i][j]) return dp[i][j].second;
        bool ans = false; 
        ans = ans || reach(i+1, j, arr, mid + arr[i][j]);
        ans = ans || reach(i, j+1, arr, mid + arr[i][j]);
        dp[i][j].first = max(dp[i][j].first, mid + arr[i][j]);
        return dp[i][j].second = ans;
    }
    bool check(int mid, vector<vector<int>> &arr){
        dp = vector<vector<pair<int, int>>> (arr.size() + 1, vector<pair<int, int>> (arr[0].size() + 1, {-1,-1}));
        return reach(0, 0, arr, mid);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int start = 1;
        int end = 1e9;
        int ans = 0;
       
        while(start <= end){
            int mid = (start + end)/2;
            if(check(mid, dungeon)) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};