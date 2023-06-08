class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        int min_buy=prices[0];
        for(int i=1;i<n;i++)
        {
            if(min_buy<prices[i])
            {
                max_profit=max(max_profit,prices[i]-min_buy);
            }
            if(min_buy>prices[i])
            {
                min_buy=prices[i];
            }
        }
        return max_profit;

    }
};