class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> answer(nums.size(), 0);
        long long int totalProd=0;
        int flag=1, count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                flag=0;    
                count++;
            }      
            else if(totalProd==0){
                totalProd++;
                totalProd*=nums[i];
            }
            else{
                totalProd*=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if (count>1) answer[i]=0;
            else if(nums[i]==0) answer[i]=totalProd;
            else if(flag==0) answer[i]=0;
            else answer[i]=totalProd/nums[i];
        }
        return answer;
    }
};