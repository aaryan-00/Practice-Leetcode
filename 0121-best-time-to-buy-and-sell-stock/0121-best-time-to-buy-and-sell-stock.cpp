class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int max_profit=0;
        // int min_buy=prices[0];
        // for(int i=1;i<n;i++)
        // {
        //     if(min_buy<prices[i])
        //     {
        //         max_profit=max(max_profit,prices[i]-min_buy);
        //     }
        //     // if(min_buy>prices[i])
        //     // {
        //     //     min_buy=prices[i];
        //     // }
        //     min_buy=min(min_buy,prices[i]);
        // }
        // return max_profit;

        int len=prices.size();
        if(len==0) return 0;
        int profit=0;
        vector<int> minn(len-1);
        int m=INT_MAX;
        for(int i=0;i<len-1;i++)
        {
            if(prices[i]<m) m=prices[i];
            minn[i]=m;
        }
        for(int i=1;i<len;i++)
        {
            if(prices[i]-minn[i-1]>profit)
            {
                profit=prices[i]-minn[i-1];
            }
        }
        return profit;

    }
};