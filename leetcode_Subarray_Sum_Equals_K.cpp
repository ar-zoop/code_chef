class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, prefixSum=0;
        map<int, int> lastRec;
        for(int i=0; i<nums.size(); i++){
            prefixSum+=nums[i];
            if(prefixSum==k) count++;
            int toFind= prefixSum-k;                
            if(lastRec.find(toFind)!=lastRec.end()){
                count+=lastRec[toFind];
            }
            if(lastRec.find(prefixSum)!=lastRec.end())
                lastRec[prefixSum]++;
            else lastRec[prefixSum]=1;
        }
        return count;
    }
};