class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int cnt=1;
        priority_queue<long,vector<long>,greater<long>> pq;
        for(auto &i:primes)
        {
            pq.push(i);
        }
        long ans=1;
        while(cnt<n)
        {
            long mini=pq.top();
            pq.pop();
            ans=mini;
            if(pq.empty()||pq.top()!=mini)
            {
                cnt++;
                for(auto &i:primes)
                {
                    pq.push(i*mini);
                }
            }

        }
        return ans;
    }
};