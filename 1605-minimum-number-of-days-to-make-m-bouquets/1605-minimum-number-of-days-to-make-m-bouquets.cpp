class Solution {
public:
    bool isPossible(vector<int> &bDay,int mid,int k,int m)
    {
        int cnt=0;
        int temp=0;
        for(int i=0;i<bDay.size();i++)
        {
            if(bDay[i]>mid) 
            {
                temp=0;
            }
            else
            {
                temp++;
                if(temp==k)
                {
                    cnt++;
                    temp=0;
                }
            }
        }
        cout<<cnt<<endl;
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi= *max_element(bloomDay.begin(),bloomDay.end());
        int mini= *min_element(bloomDay.begin(),bloomDay.end());
        int lo=1,hi=1e9;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+hi>>1;
            cout<<mid<<" ";
            if(isPossible(bloomDay,mid,k,m))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};