class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        int n=edges.size();
        vector<long long> score(n,0);
        for(int i=0;i<n;i++)
        {
            score[edges[i]]+=i;
        }
        long long sum=0;
        int ind=0;
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