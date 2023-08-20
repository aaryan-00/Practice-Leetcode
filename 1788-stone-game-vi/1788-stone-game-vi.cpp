class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>> pq,bob;
        int n=aliceValues.size();
        for(int i=0;i<aliceValues.size();i++)
        {
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int ans=0;
        int i=1;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(i&1)
            {
                ans+=aliceValues[ind];
            }
            else
            {
                ans-=bobValues[ind];
            }
            i++;
        }
        if(ans>0) return 1;
        else if(ans<0) return -1;
        return 0;
    }
};