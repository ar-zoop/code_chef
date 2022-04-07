#include <stdio.h>
int main(){
	int t,n,k,temp,i,j,swap,position;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if (k>(n/2))
			k=n-k;
		long long w[n];
		for (i=0;i<n;i++){
			scanf("%lld",&w[i]);
		}
		//selection sorting
		 for (i = 0; i < k; i++) {
		      position = i;
		      for (j = i + 1; j < n; j++) {
		         if (w[position] > w[j])
		            position = j;
		      }
		      if (position != i) {
		         swap = w[i];
		         w[i] = w[position];
		         w[position] = swap;
		      }
  		 }
  		 long long child_sum=0,chef_sum=0;
  		for (i=0;i<k;i++){
  			child_sum+=w[i];
		}
		for (i=k;i<n;i++){
			chef_sum+=w[i];
		}
		
  			printf("%lld\n",chef_sum-child_sum);
	}
	return 0;
}
