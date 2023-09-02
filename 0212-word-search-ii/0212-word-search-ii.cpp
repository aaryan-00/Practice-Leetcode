class Solution {
public:
    int n,m;
    set<string> res;
    vector<vector<bool>> vis;
    unordered_set<string> check;
    unordered_map<string,int> mp;
    string temp="";
    void getcombi(vector<vector<char>>& board,int row,int col)
    {
        if(check.count(temp))
        {
            res.insert(temp);
            
            string curr="";
            for(auto i:temp)
            {
                curr+=i;
                mp[curr]--;
            } 
            check.erase(curr);
        } 
        if(row>=n||col>=m) return;
        if(row<0||col<0) return;
        if(vis[row][col] || mp[temp]==0) return;
        vis[row][col]=true;
        temp+=board[row][col];
        getcombi(board,row+1,col);
        getcombi(board,row-1,col);
        getcombi(board,row,col+1);
        getcombi(board,row,col-1);
        vis[row][col]=false;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size(),m=board[0].size();
        vector<string> ans;

        for(auto word:words)
        {
            check.insert(word);
            string curr="";
            for(auto i:word)
            {
                curr+=i;
                mp[curr]++;
            }
        }
        mp[""]++;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                vis.clear();
                vis.resize(n+1,vector<bool>(m+1,false));
                getcombi(board,row,col);
            }
        }
        for(auto &i:res)
        {
            ans.push_back(i);
        }
        return ans;
    }
};