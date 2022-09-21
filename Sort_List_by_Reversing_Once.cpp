bool solve(vector<int>& nums) {
    int n=nums.size();
    int start=-1, flag=-1, end=n-1;
    for(int i=n-2; i>=0 ; i--){
        if(nums[i]>nums[i+1] && flag==-1){
            start=i;
            // flag=0;
        }
        /*
        else if(nums[i]>nums[i+1] && flag==0){
            start=i;
            flag=1;
        }
        */
    }
    if(start==-1)return true;
    // if(flag==1)return false;
    int i=start-1;
    while(i>=0 && nums[i]>=nums[i+1]){
        start=i;
        i--;
    }
    for(int i=start; i<n;i++){
        if(nums[i]<nums[i+1]){
            end=i;
            break;
        }
    }
    reverse(nums.begin()+ start, nums.begin()+end+1);
    for(int i=0; i<n-1; i++){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }