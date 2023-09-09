class Solution {
public:
    int find_LowEqual(vector<int> &fabo,int k)
    {
        int lo=0,hi=fabo.size()-1;
        int ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            if(fabo[mid]>k)
            {
                hi=mid-1;
            }
            else
            {
                ans=mid;
                lo=mid+1;
            }
        }
        return ans;
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> fabo;
        fabo.push_back(1);
        fabo.push_back(1);
        int sz=2;
        int limit=1;
        while(limit<=k)
        {
            int curr=fabo[sz-1]+fabo[sz-2];
            // cout<<curr<<endl;
            fabo.push_back(curr);
            sz++;
            limit=curr;
        }
        if(fabo.back()>k) fabo.pop_back();
        // cout<<fabo.back()<<endl;
        int cnt=0;
        while(k>0)
        {
            cout<<k<<endl;
            int ind=find_LowEqual(fabo,k);
            cout<<ind<<endl;
            k-=fabo[ind];
            cnt++;
        }
        return cnt;
    }
};