class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;
        for(auto &i:banned)
        {
            s.insert(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(maxSum>=i)
            {
                if(s.count(i)==0)
                {
                    ans++;
                    maxSum-=i;
                }
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};