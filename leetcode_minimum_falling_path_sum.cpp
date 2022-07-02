int memo[101][101];
int minSum(int i, int j, int size,vector<vector<int>>& matrix){
    int a=INT_MAX, b=INT_MAX, c=INT_MAX;    
    //base case
    if (i==size-1){
        return matrix[i][j];
    }
    //memoized
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    
    //cases 3^n
    a=minSum(i+1,j,size, matrix)+matrix[i][j];
    if(j>0){
        b=minSum(i+1,j-1, size, matrix)+matrix[i][j];
    }
    if(j<size-1){
        c=minSum(i+1, j+1,size,matrix)+matrix[i][j];
    }
    
    //optimized solution
    int mini=min(a,b);
    return memo[i][j]=min(mini,c);
}
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        memset(memo, -1, sizeof(memo));
        for(int j=0;j<n;j++){
            int sum=minSum(0,j,n,matrix);
            if(sum<mini){
                mini=sum;
            }
        }
        return mini;
    }
};

