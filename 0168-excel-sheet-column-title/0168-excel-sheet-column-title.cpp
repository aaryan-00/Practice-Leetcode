class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0)
        {
            int rem=columnNumber%26;
            if(rem==0) 
            {
                rem=26;
                columnNumber--;
            }
            ans=char('A'+rem-1)+ans;
            columnNumber/=26;
        }
        return ans;
    }
};