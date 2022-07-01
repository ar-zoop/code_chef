int memo[200][200];
int sub(int i, int j, int target_i, int target_j, vector<vector<int>>& grid){
    
    if(i==target_i && j==target_j)return grid[i][j];
    
    if(memo[i][j]!=-1) return memo[i][j];
    
    int left=INT_MAX,right=INT_MAX;
    
    if(i+1<=target_i)
        left=sub(i+1, j, target_i, target_j, grid);
    
    if(j+1<=target_j)
        right=sub(i, j+1, target_i, target_j, grid);

    return memo[i][j]=min;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(memo, -1, sizeof(memo));
        int count=sub(0,0,m-1, n-1, grid);
        return count;
    }
};