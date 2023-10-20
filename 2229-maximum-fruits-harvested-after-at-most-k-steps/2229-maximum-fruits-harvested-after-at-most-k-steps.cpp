class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int tot=fruits.size();
        int n=fruits[tot-1][0]+1;
        vector<long long> presum(n+1,0);
        for(auto i:fruits)
        {
            presum[i[0]+1]+=i[1];
        }
        for(int i=1;i<=n;i++)
        {
            presum[i]+=presum[i-1];
        }
        if(k==0) 
        {
            if(startPos<=n) return presum[startPos+1]-presum[startPos];
            return 0;
        }
        long long ans=0;
        //right
        if(startPos<n)
        {
            int rightpos=startPos+k+1;
            rightpos=min(rightpos,n);
            
            // cout<<rightpos<<endl;
            ans=max(ans,presum[rightpos]-presum[startPos]);
        }
        // cout<<ans<<endl;
        //left
        int leftpos=startPos-k;
        leftpos=max(leftpos,0);
        // cout<<leftpos<<endl;
        ans=max(ans,presum[min(startPos+1,n)]-presum[leftpos]);
        for(int i=1;i<min(n,k);i++)
        {
            int forward=i+startPos+1;
            forward=min(max(0,forward),n);
            int rem=k-2*i;
            int backward=startPos-rem;
            backward=max(backward,0);
            backward=min(n,backward);
            ans=max(ans,presum[forward]-presum[backward]);
        }
        for(int i=1;i<min(n,k);i++)
        {
            int backward=startPos-i;
            backward=max(min(n,backward),0);
            
            int rem=k-2*i;
            int forward=rem+startPos+1;
            forward=min(max(0,forward),n);
            ans=max(ans,presum[forward]-presum[backward]);   
        }
        return ans;

    }
};