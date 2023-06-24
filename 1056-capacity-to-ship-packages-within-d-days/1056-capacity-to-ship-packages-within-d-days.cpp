class Solution {
public:
    bool isPossible(vector<int> &w,int mid,int days)
    {
        int cnt=1;
        int curr_w=0;
        for(auto i:w)
        {
            curr_w+=i;
            if(curr_w>mid)
            {
                cnt++;
                curr_w=i;
            }
        }
        cout<<cnt<<endl;
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto i:weights)
        {
            sum+=i;
        }
        cout<<sum<<endl;
        int lo=*max_element(weights.begin(),weights.end()),hi=sum;
        int ans=1;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            cout<<mid<<" ";
            if(isPossible(weights,mid,days))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};