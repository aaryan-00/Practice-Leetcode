class Solution {
public:
    // long long minimumRemoval(vector<int>& beans) {
    //     long long ans=1e18;
    //     int n=beans.size();
    //     sort(beans.begin(),beans.end());
    //     vector<long> pre(n+1,0),suff(n+1,0);
    //     for(int i=1;i<=n;i++)
    //     {
    //         pre[i]=pre[i-1]+beans[i-1];
    //     }
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         suff[i]=suff[i+1]+beans[i];
    //     }
    //     // for(int i=0;i<=n;i++)
    //     // {
    //     //     cout<<pre[i]<<" ";
    //     // }
    //     // cout<<endl;
    //     // for(int i=0;i<=n;i++)
    //     // {
    //     //     cout<<suff[i]<<" ";
    //     // }
    //     // cout<<endl;
    //     for(int i=1;i<=n;i++)
    //     {
    //         long long preee=pre[i-1],post=suff[i];
    //         long long curr=preee+post-(n-i)*(long long)beans[i-1];
    //         ans=min(ans,curr);
            
    //     }
    //     return ans;
    // }



    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long maxi=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=beans[i];
            maxi=max(maxi,(long)beans[i]*(n-i));
        }
        
        return sum-maxi;
    }
};