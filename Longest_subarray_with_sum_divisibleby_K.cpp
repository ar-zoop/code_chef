class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int,int> lastRec;
	    int prefix=0, maxi=0;
	    for(int i=0 ;i<n;i++){
	        prefix+=arr[i];
	        
	        if(prefix%k==0) maxi=i+1;
	        
	        int rem=prefix%k;
	        if(rem < 0) rem += k;
	        if(lastRec.find(rem)!=lastRec.end()){
	            int subLen= i-(lastRec[rem]);
	            maxi=max(subLen, maxi);
	        }
	        
	        else lastRec[rem]=i;
	    }
	    return maxi;
	}
};