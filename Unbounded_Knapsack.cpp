#include<bits/stdc++.h>
int memo[1000][1000];
int findVal(int idx, int w, int n,vector<int> &value, vector<int> &weight){
    int take=INT_MIN, not_take=INT_MIN;
    //base case
    if(idx==n-1){
        return (w/weight[n-1]*value[n-1]);
    }
    if(memo[idx][w]!=-1)return memo[idx][w];
    //take or not take
    not_take=findVal(idx+1,w,n,value,weight);
    if(w>=weight[idx]){
        take=findVal(idx,w-weight[idx],n,value,weight)+value[idx];
    }
    
    //return max
    return memo[idx][w]=max(take,not_take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    memset(memo,-1,sizeof(m
    emo));
    return findVal(0,w,n,profit, weight);
}
