class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int> mpp;
        int size=nums.size();
        for(int i=0;i<size;i++){
            mpp[nums[i]]+=1;
            if (mpp[nums[i]]>1)
            {
                return true;
            }
        }
        return false;
    }
};