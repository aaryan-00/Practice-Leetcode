class Solution {
public:
    vector<long long> sum;
    long long ans=INT_MAX,k;
    void getAns(vector<int>& jobs,int ind,int k)
    {
        if(ind==jobs.size())
        {
            long long maxi=INT_MIN;
            for(auto &i:sum)
            {
                maxi=max(maxi,i);
            }
            ans=min(ans,maxi);
            return;
        }
        for(int i=0;i<k;i++)
        {
            if(i > 0 and sum[i] == sum[i-1]) continue;
            if(sum[i] + jobs[ind] >= ans) continue;
            sum[i]+=jobs[ind];
            getAns(jobs,ind+1,k);
            sum[i]-=jobs[ind];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sum.resize(k,0);
        getAns(jobs,0,k);
        return ans;
    }
};