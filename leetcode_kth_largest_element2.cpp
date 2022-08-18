class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=1;
            }
            else mpp[nums[i]]++;
        }
        map <int,int>:: iterator itr;
        int count=0;
        int pos=nums.size()-k+1;
        for(itr=mpp.begin(); itr!=mpp.end();itr++){
            count+=itr->second;
            if(count>=pos) return itr->first;
        }
        return 1;
    }
};