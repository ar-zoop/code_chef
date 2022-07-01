#include <bits/stdc++.h>
#define MOD 1000000007

int path(int i, int j, int n, int m, vector< vector< int> > &mat, vector< vector< int> > &dp){
    int left=0,right=0;
    //base cases
    if(i==n-1 && j==m-1){
        return 1;
    }
    //memoization
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //special cases
    else if(i==n-1){
        if(mat[i][j]==0){
            right=path(i,j+1,n,m, mat, dp);
        }
    }
    else if(j==m-1){
        if(mat[i][j]==0){
            left=path(i+1,j,n,m, mat, dp);
        }
    }
    else if(mat[i][j]==-1){
        return 0;
    }
    else if(mat[i][j]==0){ 
         left=path(i+1,j,n,m, mat, dp);
         right=path(i,j+1,n,m, mat, dp);
         
    }
    return dp[i][j]=(left+right)%MOD;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n,vector<int>(m,-1));
//     memset(dp,-1,sizeof(dp));
//     memset(dp,-1,dp.size());
    int count=path(0,0,n,m,mat, dp);
    return (count%MOD);
    
}