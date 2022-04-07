#include <stdio.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		long long l[n], k;
		
		for (int i=0;i<n;i++)
			scanf("%lld",&l[i]);
		//sort
		qsort(l, n, sizeof(long long), cmpfunc);
		int arr[n];
		while(q--){
			for (int i=0;i<n;i++)
				arr[i]=l[i];
			scanf("%lld",&k);
			//search k in L or find the next higher number than k			
			int low=0,high=n,mid,k_pos=-1,count=0;
			
			while(low<=high)
		    {
		        mid=(low+high)/2;
		        if(arr[mid]==k)
		        {
		            k_pos=mid;
		            break;
		        }
		        else if(arr[mid]>k)
		          high=mid-1;
		        else
		            low=mid+1;
		    }
		    if(k_pos!=mid){
		    	if (arr[mid]>k && k>arr[mid-1]){
		    		k_pos=mid;
				}
				else if (arr[mid]>k && k<arr[mid-1]){
		    		k_pos=mid-1;
				}
				else if (arr[mid]<k && k>arr[mid-1]){
		    		k_pos=mid+1;
				}
			}
//		        k_pos=mid;
//		    printf("yes k_pos=%d\n",high);
			if(k_pos==0){
				count=0;
			}
			
			else{
				int j=0, i=k_pos-1;
				while(j<i){
					if(arr[i]==k){
							i--;
							count++;
					}
					
					else{
						j++;
		 				arr[i]++;
					}
				}
			}
//			printf("cpunt=%d k_pos=%d\n",count,k_pos);
			for (int i=k_pos;i<n;i++){
//				printf("hi");
				count++;
			}
			printf("%d\n",count);
			
		
		}
				
	}

	return 0;
}
