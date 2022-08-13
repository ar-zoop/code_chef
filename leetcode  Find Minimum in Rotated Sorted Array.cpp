class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1,mini=INT_MAX, mid;
        if(nums[low]<nums[high]) return nums[0];
        while(low<=high){
            mid=(low+high)/2;
            // cout<<nums[mid];
            mini=min(nums[mid], mini);
            if(mid+1 < nums.size())
                mini=min(mini,nums[mid+1]);
            if(mid-1>=0)
                mini=min(mini,nums[mid-1]);
            if(nums[mid]>nums[low]){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return mini;
    }
};