#include <stdio.h>
#include <stdlib.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(long long*)b - *(long long*)a );
}

int main(){
	int t,n,k,i;
	scanf("%d",&t);
	while(t--){
		int count=0;
		scanf("%d %d",&n,&k);
		long long arr[n];
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		qsort(arr, n, sizeof(long long), cmpfunc);	
		

		for(i=k-1;i>=0;i--){
			count++;
		}
		for(i=k;i<n;i++){
			if(arr[k-1]==arr[i])
				count++;
			else
				break;
		}
		printf("%d\n",count);
	}
	return 0;
}
