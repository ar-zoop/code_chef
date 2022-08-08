class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1=-1, index2;
        for (int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1= i;
                break;
            }
        }
        if(index1==-1){
            reverse(nums.begin(), nums.end());
            
        }
        else{
            for (int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[index1]){
                    index2= i;
                    int temp=nums[index2];
                    nums[index2]=nums[index1];
                    nums[index1]=temp;
                    // cout<<"here";
                    // cout<<nums[index1]<<nums[index2];
                    break;
                }
            }
            swap(nums[index1], nums[index2]);
            reverse(nums.begin()+index1+1, nums.end());            
        }
        vector <int>::iterator itr;
        for(itr=nums.begin(); itr!=nums.end();itr++){
            cout<<(*itr);
        }
    }
    
};