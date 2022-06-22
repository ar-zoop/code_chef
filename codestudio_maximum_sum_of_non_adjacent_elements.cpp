#include <bits/stdc++.h>
int memo[10000];
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

    //return  max
    return memo[idx]=max(left,right);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    memset(memo, -1, sizeof(memo));
    return sub(0,nums.size(),nums);
}


//Tabulation method for this question
#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int memo[10000], n, take, not_take;
    n=nums.size();
    memset(memo,-1,sizeof(memo));
    memo[n-1]=nums[n-1];
    for(int i=0;i<n-1;i++){
        if(i==n-2) take= nums[i];
        else{
            take= memo[i+2]+nums[i] ;
        }
        not_take=0+memo[i+1];
        memo[i]=max(take,not_take);
    }
    int sum;
    for (int i==0;i<n;i++)sum+=memo[i];
}