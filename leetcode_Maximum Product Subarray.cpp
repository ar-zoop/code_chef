class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int prod=1, maxProd=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxProd=max(maxProd,prod);
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxProd=max(maxProd,prod);
            if(prod==0) prod=1;
        }
        return maxProd;
    }
};