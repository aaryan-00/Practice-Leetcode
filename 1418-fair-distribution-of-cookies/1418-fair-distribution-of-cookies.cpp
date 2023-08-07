class Solution {
public:
    vector<int> sum;
    int ans=INT_MAX,k;
    void getAns(vector<int>& cookies,int ind,int k)
    {
        if(ind==cookies.size())
        {
            int maxi=INT_MIN;
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
            if(sum[i] + cookies[ind] >= ans) continue;
            
            sum[i]+=cookies[ind];
            getAns(cookies,ind+1,k);
            sum[i]-=cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sum.resize(k,0);
        getAns(cookies,0,k);
        return ans;
    }
};