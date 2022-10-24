class Solution{
public:

    void dfs(int i, int j, vector<vector<char>>& mat){
        if(i<0 || i>mat.size()-1 || j<0 || j>mat[0].size()-1) return;
        if(mat[i][j]=='X' || mat[i][j]=='~') return;
        mat[i][j]='~';
        dfs(i+1,j,mat);
        dfs(i-1, j, mat);
        dfs(i,j-1,mat);
        dfs(i,j+1,mat);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        /*
        1. traverse the boundaries. 
        1.1 if 0 found put  a bfs on it and convert to '~'
        2. traverse the whole matrix
        2.1 if ele == ~ -> convert to 0
        2.2 else to x
        */
        int rows,cols;
        rows=mat.size();
        cols=mat[0].size();
        for(int i=0; i<rows; i++){
            if(mat[i][0]=='O'){
                dfs(i,0,mat);
            }
            if(mat[i][cols-1]=='O'){
                dfs(i,cols-1, mat);
            }
        }
        for(int j=0; j<cols;j++){
            if(mat[0][j]=='O'){
                dfs(0,j, mat);
            }
            if(mat[rows-1][j]=='O'){
                dfs(rows-1,j, mat);
            }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]=='~'){
                    mat[i][j]='O';
                }
                else{
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};