#include <bits/stdc++.h> 
int memo[15][15];
int sub(int i, int j, int target_i, int target_j){
    if(i==target_i && j==target_j)return 1;
    if(memo[i][j]!=-1) return memo[i][j];
    int left=0,right=0;
    if(i+1<=target_i)
        left=sub(i+1, j, target_i, target_j);
    if(j+1<=target_j)
        right=sub(i, j+1, target_i, target_j);

    return memo[i][j]= left+right;
}

int uniquePaths(int m, int n) {
    // Write your code here.
    memset(memo, -1, sizeof(memo));
    int count=sub(0,0,m-1, n-1);
    return count;
}