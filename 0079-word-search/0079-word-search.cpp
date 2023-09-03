class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    bool getcombi(vector<vector<char>>& board,string &word,int w_ind,int row,int col)
    {
        if(w_ind==word.size()) return true;
        if(row>=n||col>=m) return false;
        if(row<0||col<0) return false;
        if(board[row][col]==word[w_ind] && vis[row][col]==false)
        {
            // if(w_ind==word.size()-1) return true;
            vis[row][col]=true;
            if(getcombi(board,word,w_ind+1,row+1,col))
            {
                return true;
            }
            if(getcombi(board,word,w_ind+1,row-1,col))
            {
                return true;
            }
            if(getcombi(board,word,w_ind+1,row,col+1))
            {
                return true;
            }
            if(getcombi(board,word,w_ind+1,row,col-1))
            {
                return true;
            }
            vis[row][col]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(),m=board[0].size();
        vis.resize(n,vector<bool>(m,false));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(board[row][col]==word[0])
                {
                    if(getcombi(board,word,0,row,col))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }



    // int n,m;
    // bool getcombi(vector<vector<char>>& board,string &word,int w_ind,int row,int col)
    // {
    //     if(w_ind!=word.size()) return true;
    //     if(row>=n||col>=m) return false;
    //     if(row<0||col<0) return false;
    //     if(board[row][col]==word[w_ind])
    //     {
    //         // if(w_ind==word.size()-1) return true;
    //         char temp=board[row][col];
    //         board[row][col]='*';
    //         bool ans=getcombi(board,word,w_ind+1,row+1,col)||getcombi(board,word,w_ind+1,row-1,col)||getcombi(board,word,w_ind+1,row,col+1)||getcombi(board,word,w_ind+1,row,col-1);
            // if(getcombi(board,word,w_ind+1,row+1,col))
            // {
            //     return true;
            // }
            // if(getcombi(board,word,w_ind+1,row-1,col))
            // {
            //     return true;
            // }
            // if(getcombi(board,word,w_ind+1,row,col+1))
            // {
            //     return true;
            // }
            // if(getcombi(board,word,w_ind+1,row,col-1))
            // {
            //     return true;
            // }
            // board[row][col]=temp;
    //         return ans;
    //     }
    //     return false;
    // }
    // bool exist(vector<vector<char>>& board, string word) {
    //     n=board.size(),m=board[0].size();
    //     for(int row=0;row<n;row++)
    //     {
    //         for(int col=0;col<m;col++)
    //         {
    //             if(board[row][col]==word[0])
    //             {
    //                 if(getcombi(board,word,0,row,col))
    //                 {
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
};