#include <bits/stdc++.h>
int memo[1001];
int sub(int idx, int n,vector<int> &nums){
    int left=INT_MIN ,right=INT_MIN;
    //base cases
    if(idx==n-1)return nums[idx];
    if(idx>n-1)return 0;
    if(memo[idx]!=-1)return memo[idx];
    //pick
    left=sub(idx+2, n, nums)+nums[idx];

    //not pick
    right=sub(idx+1,n,nums)+0;

    //return max
    return memo[idx]=max(left,right);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    memset(memo, -1, sizeof(memo));
    int res=sub(0,nums.size(),nums);
    return res;
}