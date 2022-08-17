class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i=0;i<nums.size(); i++){
            int low=i+1, high=nums.size()-1;
            if(nums[i]>0) break;
            // int prev_nums_i=nums[i];
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(low<high){
                long long int sum=nums[i]+nums[low]+nums[high];
                if(sum==0){
                    result.push_back({nums[i],nums[low],nums[high]});
                    int prev_nums_low=nums[low], prev_nums_high=nums[high];
                    while(prev_nums_low==nums[low] && low<high){
                        cout<<"low++= ";
                        low++;
                        cout<<low<<endl;
                    }
                    while(prev_nums_high==nums[high] &&low<high){
                        cout<<"high--";
                        high--;
                        cout<<high<<endl;
                    }
                }
                else if(sum>0) high--;
                else low++;
            }
        }
        return result;
    }
};