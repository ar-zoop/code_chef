class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> temp_set;
        sort(nums.begin(),nums.end());
         
         
        for(int outer=0;outer<size-1;outer++){
            int start=outer+1;
            int end=size-1;
             if(nums[outer]==nums[outer+1]){
                continue;    
             }
             
            while(start<end){
                if(nums[outer]+nums[start]+nums[end]==0){
                temp_set.insert({nums[outer],nums[start],nums[end]});
                start++;
                end--;}
                
                else if((nums[start]+nums[end])<-nums[outer])
                        start++;
                else
                    end--;
                
            }
        }
        set<vector<int>>::iterator itr;
        for(itr=temp_set.begin();itr!=temp_set.end();itr++){
            ans.push_back(*itr);
        }
     return ans;

    }
};