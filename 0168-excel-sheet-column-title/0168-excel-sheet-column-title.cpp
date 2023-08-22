class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        if(columnNumber==1) return "A";
        while(columnNumber>26)
        {
            int rem=columnNumber%26;
            if(rem==0) 
            {
                rem=26;
                columnNumber--;
            }
            char temp= char('A'+rem-1);
            ans=temp+ans;
            columnNumber/=26;
        }
        cout<<columnNumber<<endl;
        char temp= char('A'+columnNumber - 1);
        return temp+ans;
    }
};