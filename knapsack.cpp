#include <bits/stdc++.h>
using namespace std;
int memo[3];
int knapsack(int idx, int ks, int wt[], int val[], int n){
    int take=INT_MIN, not_take=INT_MIN;
    //base case
    // int n=sizeof(wt)/sizeof(int);
    if(idx==n-1){
        if(ks-wt[idx]>=0)return val[idx];
        return 0;
    }
    //take
    if(ks-wt[idx]>=0)
        take=knapsack(idx+1, ks-wt[idx], wt, val, n)+val[idx];
    //not take
        not_take=knapsack(idx+1, ks, wt, val, n)+0;

    //return max
    return max(take, not_take);
}
int main(){
    int wt[3]={3,4,5};
    int val[3]={30,50,60};
    int ks=6;
    int maxi=knapsack(0, ks, wt, val, 3);
    cout<<maxi;
    return 0;
}