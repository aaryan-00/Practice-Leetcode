class Solution {
public:
    bool isPossible(vector<int>& batteries, long long time, int computers){
        long long totTime = 0;
        for(long long currTime : batteries)
        {
            totTime += min(time, currTime);
        }
        
        return totTime>=time*computers;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(auto &i:batteries)
        {
            sum+=i;
        }
        long long low=0,high=sum/n,ans=0;
        while(low <= high){
            
            long long mid = low+high >>1;
            if(isPossible(batteries, mid, n))
            {
                ans = mid;
                low = mid+1;
            }
            else{
                 high = mid-1;
            }
        }
        return ans;
    }
};