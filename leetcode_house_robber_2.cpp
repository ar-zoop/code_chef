#include <bits/stdc++.h>
using namespace std;

long long int sub(int idx, vector <int> nums, int size, int flag, long long int memo[]){
    int pick;
    //base cases
    if(flag==1 && idx==size-1) return 0; 
    if(idx==size-1){
        return nums[idx];
    }
    if(idx>size-1)return 0;
    //pick
    if(memo[idx]!=-1) return memo[idx];
    if(idx==0){
        // flag=1;
        pick= sub(idx+2, nums, size, 1, memo)+ nums[idx];        
    }
    else{
        pick= sub(idx+2, nums, size, flag, memo)+ nums[idx]; 
    }
    //not pick
    int not_pick=sub(idx+1, nums, size, flag, memo)+0;
    //return 
    memo[idx]= max(pick,not_pick);
    return max(pick,not_pick);
    
}

// class Solution {
// public:
    int rob(vector<int>& nums) {
        long long int memo[1001];
        memset(memo, -1, sizeof(memo));
        int n=nums.size();
        long long int res=sub(0,nums,n, 0, memo);
        return res;
    }
// };

int main(){
    vector <int> vec={1,2,3};
    long long int a=rob(vec);
    cout<<a;
}