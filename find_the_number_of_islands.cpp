class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i>grid.size()-1 || i<0 || j<0 || j>grid[0].size()-1) return;
        if(grid[i][j]!='1') return;
        grid[i][j]='x';
        dfs(i+1, j,grid);
        dfs(i-1, j,grid);
        dfs(i, j+1,grid);
        dfs(i, j-1,grid);
        dfs(i+1, j+1,grid);
        dfs(i+1, j-1,grid);
        dfs(i-1, j+1,grid);
        dfs(i-1, j-1,grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};