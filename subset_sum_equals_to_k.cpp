#include <bits/stdc++.h>
int memo[1000][1000];
bool sub(int idx, int target,vector<int> &arr, int n){
    bool pick=false, not_pick=false;
    //base case
    if(target==0){
        return true;
    }
    if(idx==n-1){
        if(target==arr[idx]) return true;
        return false;
    }
    //memoization
    if(memo[idx][target]!=-1){
        return memo[idx][target];
    }
    //cases
    if(arr[idx]<=target){
        pick =sub(idx+1, target-arr[idx], arr,n);
        if(pick==true) {            
            return memo[idx][target]= true;
        }
    }
    not_pick=sub(idx+1, target, arr,n);
    if(not_pick==true) {
        return memo[idx][target]=true;
    }
   
    return  memo[idx][target]= false;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    memset(memo,-1,sizeof(memo));
    return sub(0,k,arr,n);
}