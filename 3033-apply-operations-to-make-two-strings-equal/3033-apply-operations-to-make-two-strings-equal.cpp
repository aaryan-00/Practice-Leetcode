class Solution {
public:
    int dp[501][501];
    int getAns(vector<int> &nums, int i, int j, int x){
        
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int k = nums[i+1]-nums[i] + getAns(nums, i+2, j, x);
        int y = nums[j] - nums[j-1] + getAns(nums, i, j-2, x);
        
        int z = x + getAns(nums, i+1, j-1, x);
        
        dp[i][j] = min(min(k,y),z);    
        return dp[i][j];
        
    }
    
    int minOperations(string s1, string s2, int x) {
        memset(dp,-1,sizeof(dp));
        vector<int> nums;
        
        for(int i=0,j=0; i<s1.size(); i++,j++){
            if(s1[i]!=s2[j]){
                nums.push_back(i);
            }
        }
        int n = nums.size();
        if(n%2==1){
            return -1;
        }
        return getAns(nums, 0, n-1, x);
    }
};