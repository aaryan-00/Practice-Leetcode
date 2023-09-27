class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // long long total=0;
        // for(long long i=0; i<maxHeights.size();i++){
        //     total+=maxHeights[i];
        // }
        long maxi=0;
        for(long i=0; i<maxHeights.size();i++)
        {
            long sub=maxHeights[i],prev=maxHeights[i];
            for(long j=i-1;j>=0;j--)
            {
                if(maxHeights[j]>prev)
                {
                    sub += prev;
                }
                else
                {
                    prev = maxHeights[j];
                    sub+=prev;
                } 
            }
            prev=maxHeights[i];
            for(long k=i+1;k<maxHeights.size();k++)
            {
                // cout<<prev<<endl;
                if(maxHeights[k]>=prev)
                {
                    sub += prev;
                }
                else
                {
                    prev = maxHeights[k];
                    sub+=prev;
                }
            }
            maxi=max(sub,maxi);
        }
        return maxi;
        
    }
};