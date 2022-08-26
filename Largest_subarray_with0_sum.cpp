class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxi=0, prefixSum=0;
        map<int, int> lastRec;
        for(int i=0; i<n; i++){
            prefixSum+=A[i];
            if(prefixSum==0){
                int subLen= i+1;
                maxi=max(subLen,maxi);
            }
            else if(lastRec.find(prefixSum)==lastRec.end()){
                lastRec[prefixSum]=i;
            }
            else{
                map<int,int>::iterator imp= lastRec.find(prefixSum);
                int subLen= i- (imp->second);
                maxi=max(subLen,maxi);
            }
        }
        return maxi;
    }
};