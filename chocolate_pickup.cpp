#include <bits/stdc++.h>
int memo[50][50][50];

int maxiCount(int i, int j1, int j2, int r, int c,vector<vector<int>> &grid){
    int a=INT_MIN,  maxi= INT_MIN;
    //base case
     if(j1>c-1 || j1<0 || j2>c-1 || j2<0) return -1e8;
    
    if(i==r-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    //memoized
    if(memo[i][j1][j2]!=-1)return memo[i][j1][j2];
    //explore all paths
    for (int dj1=-1;dj1<2;dj1++){
        for (int dj2=-1;dj2<2;dj2++){
            if (j1== j2){
                a=maxiCount(i+1, j1+dj1, j2+dj2,r,c,grid) + grid[i][j2];
            }
            else{
                a=maxiCount(i+1, j1+dj1, j2+dj2,r,c, grid) + grid[i][j2] + grid[i][j1] ;
            }
           if(a>maxi){
               maxi=a;
           }
        }        
    }
    //return max
    return memo[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    memset(memo, -1, sizeof(memo));
    return maxiCount(0, 0, c-1, r, c, grid);
}