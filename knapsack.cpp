#include <bits/stdc++.h>
using namespace std;
int memo[3][7];
int knapsack(int idx, int ks, int wt[], int val[], int n){
    int take=INT_MIN, not_take=INT_MIN;
    //base case
    // int n=sizeof(wt)/sizeof(int);
    if(idx==n-1){
        if(ks-wt[idx]>=0)return val[idx];
        return 0;
    }
    if (memo[idx][ks]!=-1)return memo[idx][ks];
    //take
    if(ks-wt[idx]>=0)
        take=knapsack(idx+1, ks-wt[idx], wt, val, n)+val[idx];
    //not take
        not_take=knapsack(idx+1, ks, wt, val, n)+0;

    //return max
    return memo[idx][ks]=max(take, not_take);
}
int main(){
    int wt[3]={3,4,5};
    int val[3]={30,70,60};
    int ks=0;
    memset(memo, -1, sizeof(memo));
    int maxi=knapsack(0, ks, wt, val, 3);
    cout<<maxi;
    return 0;
}