class Solution {
public:
    map<vector<int>,int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int sum=0;
        for(int i=0;i<needs.size();i++)
        {
            sum+=needs[i]*price[i];
        }
        if(dp.find(needs)!=dp.end()) return dp[needs];
        for(auto offer:special)
        {
            vector<int> clone=needs;
            int j=0;
            for(;j<needs.size();j++)
            {
                int diff=clone[j]-offer[j];
                if(diff<0)
                {
                    break;
                }
                clone[j]=diff;
            }
            if(j==needs.size())
            {
                sum=min(sum,offer[j]+shoppingOffers(price,special,clone));
            }
        }
        return dp[needs]=sum;

        
    }
};