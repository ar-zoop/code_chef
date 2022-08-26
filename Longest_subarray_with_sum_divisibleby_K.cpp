/*14 10
10 16 8 13 19 16 2 2 12 6 4 15 13 2*/

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
	        if(lastRec.find(rem)!=lastRec.end()){
	            map<int , int> :: iterator imp=lastRec.find(rem);
	            int subLen= i-(imp->second);
	            maxi=max(subLen, maxi);
	        }
	        
	        if(lastRec.find(rem)==lastRec.end()) lastRec[rem]=i;
	    }
	    return maxi;
	}
};