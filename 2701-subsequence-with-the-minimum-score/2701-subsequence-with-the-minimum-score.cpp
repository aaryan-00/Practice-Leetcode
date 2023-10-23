class Solution {
public:
    int minimumScore(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<int> pre(m+1,0),suff(m+1,0);
        int j=0;
        for(int i=0;i<m && j<n;i++)
        {
            if(s[i]==t[j])
            {
                pre[i+1]=1+pre[i];
                j++;
            }
            else
            {
                pre[i+1]=pre[i];
            }
        }
        j=n-1;
        for(int i=m-1;i>=0 && j>=0;i--)
        {
            if(s[i]==t[j])
            {
                suff[i]=1+suff[i+1];
                j--;
            }
            else
            {
                suff[i]=suff[i+1];
            }
        }
        int ans=1e5;
        for(int i=0;i<=m;i++)
        {
            ans=min(ans,n-(pre[i]+suff[i]));
        }
        return max(ans,0);
    }
};