class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    vector<bool> rowCheck,upDiagonal,downDiagonal;
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
            // if(isSafe(col,row,n))
            // {
            //     temp[row][col]='Q';
            //     solve(col+1,n);
            //     temp[row][col]='.';
            // }

            // or
            if(rowCheck[row]==0 && downDiagonal[row+col]==0 && upDiagonal[n-1+row-col]==0)
            {
                rowCheck[row]=1, downDiagonal[row+col]=1, upDiagonal[n-1+row-col]=1;
                temp[row][col]='Q';
                solve(col+1,n);
                temp[row][col]='.';
                rowCheck[row]=0, downDiagonal[row+col]=0, upDiagonal[n-1+row-col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        temp.resize(n);
        rowCheck.resize(n,false);
        upDiagonal.resize(2*n-1,false);
        downDiagonal.resize(2*n-1,false);
        string curr(n,'.');
        for(auto &i:temp)
        {
            i=curr;
        }
        solve(0,n);
        return ans;
    }
};