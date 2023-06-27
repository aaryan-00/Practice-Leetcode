class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ')
        {
            i++;
        }
        while(n-1>=0 && s[n-1]==' ')
        {
            n--;
        }
        string temp="";
        while(i<n)
        {
            if(s[i]==' ')
            {
                ans=temp+ans;
                ans=" "+ans;
                temp="";
                while(s[i]==' ' && i<n)
                {
                    i++;
                } 
            }
            else
            {
                temp+=s[i];
                i++;
            }
        }
        ans=temp+ans;
        
        return ans;
    }
};