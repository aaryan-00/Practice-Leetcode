class Solution {
public:
    vector<string> ans;
    void getAns(int i,int open,string temp)
    {
        if(i==0)
        {
            if(open==0) ans.push_back(temp);
            return;
        }
        if(open>0)
        {
            getAns(i-1,open+1,temp+'(');
            getAns(i-1,open-1,temp+')');
        }
        else
        {
            getAns(i-1,open+1,temp+'(');
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        getAns(2*n,0,"");
        return ans;
    }
};