#include<bits/stdc++.h>
using namespace std;
int memo[50][50][50][50];

int maxiCount(int i1, int i2, int j1, int j2, int c,vector<vector<int>> &grid){
    int a=INT_MIN,  maxi= INT_MIN;
    //base case
    if(grid[i1][j1]==-1 || grid[i2][j2]==-1 ) return -1e8;
    if(i1>n-1 || i2<0 || j1 >n-1 || j2<0) return -1e8;
    if(i1==n-1 && j1==n-1 && i2==0 && j2==0) return grid[i1][j1] + grid[i2][j2];
    if(i1==i2 && j1==j2) return grid[i1][j1];
    
    //memoized
    if(memo[i1][i2][j1][j2]!=-1)return memo[i1][i2][j1][j2];
    
    //explore all paths
    int adown1= maxiCount(i1+1, i2-1, j1, j2, c, grid)+grid[i1][j1]+grid[i2][j2];
    int adown2= maxiCount(i1+1, i2, j1, j2-1, c, grid+grid[i1][j1]+grid[i2][j2]);
    int bdown1= maxiCount(i1, i2-1, j1+1, j2, c, grid)+grid[i1][j1]+grid[i2][j2];
    int bdown2= maxiCount(i1, i2, j1+1, j2-1, c, grid)+grid[i1][j1]+grid[i2][j2];
    
    //return max
    return memo[i1][i2][j1][j2]=maxi;
}

// class Solution {
// public:
int cherryPickup(vector<vector<int>>& grid) {
    memset(memo, -1, sizeof(memo));
    int n= grid.size();
    return maxiCount(0, 0, n-1, n-1, n-1, grid);
}
// };

int main(){

    vector<vector<int>> grid= [[0,1,-1][1,0,-1][1,1,1]];
    int a=cherryPickup(grid);
    cout<<a;
    return 0;
}