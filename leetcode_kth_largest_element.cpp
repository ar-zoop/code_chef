class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]]++;
            }
            else{
                mpp[nums[i]]=1;
            }
        }
        map<int,int>::iterator itr;
        int pos=nums.size()-k+1;
        for(itr=mpp.begin();itr!=mpp.end();itr++){
            if(itr->second > 1){
                for(int i=1;i<=itr->second;i++) {
                    pos--;
                    if(pos==0) return itr->first;
                }
            }
            else{
                pos--;
                if(pos==0) return itr->first;
            }
        }
      return -1;
    }
};