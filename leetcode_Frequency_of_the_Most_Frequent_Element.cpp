class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int count=1;
        int n= nums.size();
        int diff=0;
        sort(nums.begin(),nums.end());
            
     
        for(int j=n-1;j>=0;j--){
        for(int i=j-1;i>=0;i--){
            while(k!=0){
                diff=nums[j]-nums[i];
                
                if(diff>k || k==0){
                    break;
                }
                
                if((diff)<=k){
                    count++;
                    k=k-diff;
                    break;
                }
            }
        }
        

        }
        return count;
        
    }
};