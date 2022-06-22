#include <bits/stdc++.h>
// int memo[]
int sub(int idx, int n,vector<int> &nums){
    int maxSum=INT_MIN;
    //base cases
    if(idx==n-1){
//         cout<<"idx==n-1:  "<<idx<<endl;
        return nums[idx];
    }
    if(idx>n-1)return 0;
    //memoization check

    //pick
    for (int i=2;i<n;i++){
        
        if(idx+i<n){
//             cout<<"idx= "<<idx<<endl;
            int leftJump=sub(idx+i, n, nums)+ nums[idx];            
           maxSum=max(leftJump,maxSum);
            // cout<<"maxSum= "<<maxSum<<endl;
//             cout<<maxSum<<endl;
        }
        return nums[idx];
    }
    //non pick
    int rightJump=sub(idx,n,nums);
    maxSum=max(leftJump,maxSum,rightJump);

    return maxSum;

    
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans=INT_MIN;
    for(int i=0;i<nums.size();i++){
        int res=sub(i,nums.size(),nums);
        ans=max(res,ans);
    }
    return ans;
}