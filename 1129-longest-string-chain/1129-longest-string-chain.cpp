class Solution {
public:
    bool check(string &a,string &b)
    {
        if(a.size()!=b.size()+1)
        {
            return false;
        }
        int i=0,j=0;
        while(i<a.size())
        {
            if(j<b.size() && a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==a.size() && j==b.size())
        {
            return true;
        }
        return false;
    }
    static bool comp(string& s1, string& s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(),comp);
        vector<int> dp(n,1);
        for(int i=1; i<=n-1; i++)
        {
            for(int prev_index = 0; prev_index <=i-1; prev_index ++)
            {
                if(check(words[i],words[prev_index]) && 1+dp[prev_index]>dp[i] )
                {
                    dp[i] =1 + dp[prev_index];
                }
            }
        }
        int ans = -1;
        for(int i=0; i<=n-1; i++){
            if(dp[i]>ans)
            {
                ans=dp[i];
            }
        }
        return ans;
    }
};