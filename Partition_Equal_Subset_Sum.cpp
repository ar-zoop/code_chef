int memo[200][10000];

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
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size(), sum=0;
        memset(memo,-1,sizeof(memo));
        for(auto x=nums.begin();x!=nums.end();x++){
            sum+=*x;
        }
        if(sum%2!=0) return false;
        return sub(0,sum/2,nums,n);
    }
};

