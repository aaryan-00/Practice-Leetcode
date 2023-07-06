class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> score(n,0);
        for(int i=0;i<n;i++)
        {
            score[edges[i]]+=i;
        }
        long long sum=0,ind=0;
        for(int i=0;i<n;i++)
        {
            if(sum<score[i])
            {
                sum=score[i];
                ind=i;
            }
        }
        return ind;
    }
};