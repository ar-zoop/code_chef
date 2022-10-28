class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int count=0, start,end;
	    sort(arr, arr+n);
	    for(int i=0; i<n-2;i++){
	       // tempsum=arr[i];
	        start=i+1;
	        end=n-1;
	        while(start<end){
    	        if(arr[i]+arr[start]+arr[end]<sum){
    	            count+=(end-start);
    	           // continue;
    	           start++;
    	        }
    	        else{
    	            end--;
    	        }
	        }
	    }
	    return count;
	}
		 

};