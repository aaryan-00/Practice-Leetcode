class Solution {
public:
    vector<int> dp;
    int getCost(vector<int>& days, vector<int>& costs,int ind)
    {
        if(ind>=days.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long cost=INT_MAX;
        long oneDay=1LL*costs[0]+getCost(days,costs,ind+1);
        // // cout<<cost<<endl;
        cost=min(cost,oneDay);
        int limit=days[ind]+7-1;
        int upper1 = upper_bound(days.begin(), days.end(), limit) - days.begin();
        // cout<<upper1<<endl;
        long sevenDay=1LL*costs[1]+getCost(days,costs,upper1);
        cost=min(cost,sevenDay);
        limit=days[ind]+30-1;
        upper1 = upper_bound(days.begin(), days.end(), limit) - days.begin();
        long largeDay=1LL*costs[2]+getCost(days,costs,upper1);
        cost=min(cost,largeDay);
        return dp[ind]=cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1);
        return getCost(days,costs,0);
    }
};