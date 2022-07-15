class Solution {
public:
    int sub(int idx, int mustTake,vector<int>& nums,vector<vector<int>> &memo){
        int take=INT_MIN, not_take=INT_MIN;
        //base case
        if(idx==(nums.size()-1)) {
            return nums[idx];
        }
        if(memo[idx][mustTake]!=-1)return memo[idx][mustTake];
        //cases
        if(mustTake==true){
            take=sub(idx+1, true, nums,memo)+nums[idx];
        }
        else{            
            not_take=sub(idx+1,false, nums, memo)+0;
            take=sub(idx+1, true, nums, memo)+nums[idx];
        }
        cout<<max(not_take,take)<<" " ;
        return memo[idx][mustTake]=max(not_take,take);
    }
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> memo{10000, vector<int>(2, -1)};
        return( sub(0, false, nums,memo));
        
    }
};