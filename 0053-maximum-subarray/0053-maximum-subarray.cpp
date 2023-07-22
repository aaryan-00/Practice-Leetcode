class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int maxAtPoint=0;
        for(auto &i:nums)
        {
            maxAtPoint+=i;
            if(maxAtPoint>maxSum) maxSum=maxAtPoint;
            if(maxAtPoint<0) maxAtPoint=0;
        }
        return maxSum;
    }
};