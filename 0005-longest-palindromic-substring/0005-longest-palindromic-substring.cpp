class Solution {
public:
    string ans="";
    void find_palindrome(string &s, int left,int right)
    {
        while(left>=0 && right<s.size())
        {
            if(s[left]!=s[right])
            {
                break;
            }
            left--,right++;
        }
        if(ans.size()<right-left)
        {
            ans=s.substr(left+1,right-left-1);
        }
    }
    string longestPalindrome(string s) {
        // for(int i=0;i<s.size();i++)
        // {
        //     find_palindrome(s,i,i);
        //     find_palindrome(s,i,i+1);
        // }
        // return ans;
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                if(dp[i][j]>maxi)
                {
                    int s_Ind=i-dp[i][j];
                    string curr=s.substr(s_Ind,dp[i][j]);
                    string temp=curr;
                    reverse(curr.begin(),curr.end());
                    if(curr==temp)
                    {
                        maxi=dp[i][j];
                        ans=curr;

                    }
                }
            }
        }
        return ans;
    }
};