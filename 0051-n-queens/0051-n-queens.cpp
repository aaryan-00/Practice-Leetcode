class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool isSafe(int col,int row,int n)
    {
        int r=row,c=col;
        while(c--)
        {
            if(temp[r][c]=='Q') return false;
        }
        r=row,c=col;
        while(r>=0 && c>=0)
        {
            if(temp[r--][c--]=='Q') return false;
        }
        r=row,c=col;
        while(r<n && c>=0)
        {
            if(temp[r++][c--]=='Q') return false;
        }
        return true;
    }
    void solve(int col,int n)
    {
        if(col==n )
        {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(col,row,n))
            {
                temp[row][col]='Q';
                solve(col+1,n);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        temp.resize(n);
        string curr(n,'.');
        // for(auto &i:temp)
        // {
        //     i=curr;
        // }
        for (int i = 0; i < n; i++) {
            temp[i] = curr;
        }
        solve(0,n);
        return ans;
    }
};