class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n&&!vis[newrow][newcol]&&board[newrow][newcol]=='O'){
                dfs(board,vis,newrow,newcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1)
                {
                    if(board[i][j]=='O')
                    {
                        dfs(board,vis,i,j);
                    }
                }
            }
        }
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        

    }
};