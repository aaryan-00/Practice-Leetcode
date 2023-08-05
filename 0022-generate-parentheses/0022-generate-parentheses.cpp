class Solution {
public:
    vector<string> ans;
    string temp="";
    void getAns(int i,int open)
    {
        if(i==0)
        {
            if(open==0) ans.push_back(temp);
            return;
        }
        if(open>0)
        {
            temp+='(';
            getAns(i-1,open+1);
            temp.pop_back();
            temp+=')';
            getAns(i-1,open-1);
            temp.pop_back();
        }
        else
        {
            temp+='(';
            getAns(i-1,open+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        getAns(2*n,0);
        return ans;
    }
};