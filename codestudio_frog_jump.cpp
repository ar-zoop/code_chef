#include <bits/stdc++.h>

int memo[100001];

int sub(int idx,  int n, vector<int> &heights){
    int left, right=INT_MAX;
    //base cases
    if(idx==n-1) return 0;
    if(memo[idx]!=-1) return memo[idx];
    left=sub(idx+1,n,heights) + abs(heights[idx]-heights[idx+1]);
    
    if(idx+2 < n){
        right=sub(idx+2, n, heights)+ abs(heights[idx]-heights[idx+2]);
    }
    memo[idx]=min(left,right);
   return min(left,right);
//     cout<<mini<<endl;
//     return mini;
    // return min;
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    memset(memo,-1,sizeof(memo));
    int min= sub(0,n,heights);
    return min;

}