class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            vector<int> cnt(26,0);
            int mini=INT_MAX, maxi=INT_MIN;
            for(int j=i;j<n;j++)
            {
                int curr=s[j]-'a';
                cnt[curr]++;
                maxi=max(maxi,cnt[curr]);
                mini=cnt[curr];
                for(int k=0;k<26;k++)
                {
                    if(cnt[k]>=1)
                    {
                        mini=min(mini,cnt[k]);
                    }
                }
                ans += maxi-mini;
            }
        }
        return ans;
    }
};