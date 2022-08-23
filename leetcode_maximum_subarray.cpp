class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN, sum=0, start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[start]<0) {
                max_sum=max(max_sum, nums[start]);
                start++;
            }
            else{
                sum+=nums[i];
                max_sum=max(sum, max_sum);
                if(sum<0){
                    start=i+1;
                    sum=0;
                }
            }
        }
        return max_sum;
    }
};