class Solution {
public:
    bool isPossible(vector<int> &piles,int mid,int h)
    {
        long cnt=0;
        for(int i=0;i<piles.size();i++)
        {
            cnt+=(piles[i]/mid);
            if(piles[i]%mid)cnt++;
        }
        cout<<cnt<<endl;
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi= *max_element(piles.begin(),piles.end());
        int lo=1,hi=maxi;
        int ans=0;
        while(lo<=hi)
        {
            int mid=lo+hi>>1;
            cout<<mid<<" ";
            if(isPossible(piles,mid,h))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};