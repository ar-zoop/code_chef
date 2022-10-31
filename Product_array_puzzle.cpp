class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        vector <long long int> prefix(n);
        vector <long long int>suffix(n);
        // long long int prod=1;
        prefix[0]=1;
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        
        suffix[n-1]=1;
        
        for(int i=n-2; i>=0; i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        
        for(int i=0; i<n;i++){
            nums[i]=prefix[i]*suffix[i];
        }
        return nums;
    }
};