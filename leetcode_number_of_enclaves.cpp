class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& board, int R, int C){
        if(i<0 || i>=R || j<0 || j>=C || board[i][j]!=1)return;
        board[i][j]=-1;
        dfs(i+1,j,board, R, C);
        dfs(i-1,j,board, R, C);
        dfs(i,j-1,board, R, C);
        dfs(i,j+1,board, R, C);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int R=grid.size(), C=grid[0].size();
        for(int i=0; i<R; i++){
            if(grid[i][0]==1) dfs(i,0, grid, R, C);
            if(grid[i][C-1]==1)dfs(i,C-1, grid, R, C);
        }
        for(int j=0; j<C; j++){
            if(grid[0][j]==1) dfs(0,j, grid, R, C);
            if(grid[R-1][j]==1)dfs(R-1,j, grid, R, C);
        }
        int count=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]==-1)grid[i][j]=1;
                else if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};