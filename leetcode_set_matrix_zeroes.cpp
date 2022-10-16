
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();
        int row_f=-1, col_f=-1;
        for(int i=1; i<row; i++){
            if(matrix[i][0]==0){
                row_f=i;
                break;
            }
        }
        for(int j=1;j<column;j++){
            if(matrix[0][j]==0){
                col_f=j;
                break;
            }
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<column; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;}
            }
        }
        
        for(int i=1; i<row; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<column; j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1; j<column; j++){
            if(matrix[0][j]==0){
                for(int i=0; i<row; i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
            for(int j=0;j<column;j++){
                matrix[0][j]=0;
            }
        }
        if(row_f>-1){
            for(int i=0; i<row; i++){
                    matrix[i][0]=0;
                }
            for(int j=0; j<column;j++){
                matrix[row_f][j]=0;
            }
        }
        if(col_f>-1){
            for(int j=0; j<column; j++){
                    matrix[0][j]=0;
            }
            for(int i=0; i<row; i++){
                matrix[i][col_f]=0;
            }
        }
        
        
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};