class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if(temp.size()==0) return false;
                if(s[i]==')' && temp.top()=='(')temp.pop();
                else if(s[i]=='}' && temp.top()=='{')temp.pop();
                else if(s[i]==']' && temp.top()=='[')temp.pop();
                else return false;
            }
            else
            {
                temp.push(s[i]);
            }
        }
        return temp.size()==0;
    }
};