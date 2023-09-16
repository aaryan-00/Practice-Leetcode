class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> num(101,0);
        for(auto i:nums)
        {
            for(int j=i[0];j<=i[1];j++)
            {
                num[j]++;
            }
        }
        int cnt=0;
        for(int i=1;i<=100;i++)
        {
            if(num[i]) cnt++;
        }
        return cnt;
    }
};