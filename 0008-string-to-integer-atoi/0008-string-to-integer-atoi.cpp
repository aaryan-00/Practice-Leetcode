#include <limits.h>
class Solution {
public:
    int myAtoi(string s) {
        string ans="";
        int i=0;
        while(s[i]==' ' && i<s.size())
        {
            i++;
        }

        for(;i<s.size();)
        {
            if(s[i]=='-')
            {
                ans+=s[i];
                i++;
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    ans+=s[i];
                    i++;
                }
                break;
            }
            else if(s[i]=='+')
            {
                i++;
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    ans+=s[i];
                    i++;
                }
                break;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                while(i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    ans+=s[i];
                    i++;
                }
                break;
            }
            else 
            {
                i++;
                break;
            }
        }
        // cout<<ans<<endl;
        double res=0;
        long long sign=1;
        int j=0;
        if(ans[0]=='-')
        {
            sign=-1;
            j=1;
        }
        for(;j<ans.size();j++)
        {
            res=res*10+ans[j]-'0';
        }
        res=res*sign;

        if(res>INT_MAX) res=INT_MAX;
        if(res<INT_MIN) res=INT_MIN;
        return (int)res;
    }
};