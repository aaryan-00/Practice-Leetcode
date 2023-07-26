class Solution {
public:
    bool check(vector<int>& dist,int mid,double hour)
    {
        double hrs=0;
        int n=dist.size();
        for(int i=0;i<n-1;i++)
        {
            int curr=(dist[i]+mid-1)/mid;
            hrs+=curr;
        }
        hrs+=double(dist[n-1])/mid;
        return hrs<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // if (dist.size() > ceil(hour)) {
        //     return -1;
        // }
        int ans=-1;
        int mini=1,maxi=1e7;
        while(mini<=maxi)
        {
            int mid=mini+maxi>>1;
            // cout<<mini<<" "<<maxi<<" "<<mid<<endl;
            if(check(dist,mid,hour))
            {
                ans=mid;
                maxi=mid-1;
            }
            else
            {
                mini=mid+1;
            }
        }
        return ans;
    }
};