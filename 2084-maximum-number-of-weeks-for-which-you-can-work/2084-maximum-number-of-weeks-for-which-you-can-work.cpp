class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxi=-1,sum=0;
        int n=milestones.size();
        for(int i=0;i<n;i++)
        {
            sum+=milestones[i];
            maxi=max(maxi,1LL*milestones[i]);
        }
        sum-=maxi;  
        // cout<<sum<<" "<<maxi<<endl; 
        if(sum>=maxi) return sum+maxi;  
        return sum*2+1;
    }
};