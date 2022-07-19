class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>::iterator itr;
        vector<int> v;
        int n=nums.size();
        map<int,int>mpp;
        map<int,int>::iterator imp;
        for(itr=nums.begin();itr!=nums.end();itr++){
            if(mpp.find(*itr)==mpp.end()){
                mpp[*itr]=1;
            }
            else{
                mpp[*itr]++;
            }
        }
        for(imp=mpp.begin();imp!=mpp.end();imp++){
            if((*imp).second>n/3){
                v.push_back((*imp).first);
            }
        }
        return v;
    }
};