class Solution {
public:
    string largestOddNumber(string num) {
        // string ans="";
        int i=num.size()-1;
        while(i>=0 && (num[i]-'0')%2==0)
        {
            i--;
        }
        // cout<<'8'-'0'<<endl;
        // cout<<i<<endl;
        return num.substr(0,i+1);
    }
};