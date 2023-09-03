class Solution {
public:
    int ans=0,temp,n,m;
    // void dfs(int i,int j,vector<vector<int>>& grid)
    // {
    //     if(i<0||j<0||i>=n||j>=m) return;
    //     if(grid[i][j]==1)
    //     {
    //         temp++;
    //         grid[i][j]=0;
    //         for(int k=0;k<m;k++)
    //         {
    //             if(grid[i][k])
    //             {
    //                 dfs(i,k,grid);
    //             }
    //         }            
    //         for(int k=0;k<n;k++)
    //         {
    //             if(grid[k][j])
    //             {
    //                 dfs(k,j,grid);
    //             }
    //         }   
    //     }
    // }
    // int countServers(vector<vector<int>>& grid) {
    //     n=grid.size(),m=grid[0].size();
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(grid[i][j]==1)
    //             {
    //                 temp=0;
    //                 dfs(i,j,grid);
    //                 if(temp>1)ans+=temp;
    //             }
    //         }
    //     }
    //     return ans;
    // }



class UnionFind {
public: 
    vector<int> parent; 
    vector<int> sizes;
    UnionFind(int n){
        parent.resize(n+1);
        sizes.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i; 
            sizes[i]=1;
        }
    }
    int findParent(int v) {
        if(parent[v]==v) return v;
        return parent[v]=findParent(parent[v]);
    }
    void Union(int a , int b) {
        a=findParent(a);
        b=findParent(b);
        if(a!=b)
        {
            if(sizes[b]>sizes[a])
            {
                swap(b,a);
            }
            parent[b]=a;
            sizes[a]+=sizes[b];
            sizes[b]=0;
        }
    }  
};

    int countServers(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        UnionFind uf(n*m);

        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;

                    while(col < m) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;
                            uf.Union(cellInd,neighCellInd);
                        }
                        col++;
                    }
                }
            }
        }


        for(int col = 0;col<m;col++) {
            for(int row = 0;row<n;row++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;
                    while(row < n) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;
                            uf.Union(cellInd,neighCellInd);
                        }
                        row++;
                    }
                }
            }
        }
        for(int i=0;i<=(n*m);i++)
        {
            if(uf.sizes[i]>1)ans+=uf.sizes[i];
        }
        return ans;
    }
};