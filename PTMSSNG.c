#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int max=(4*n)-1;
		long long x[max],y[max];
		for (int i=0;i<((4*n)-1);i++){
			scanf("%lld %lld",&x[i],&y[i]);
		}
		qsort(x, max, sizeof(long long), cmpfunc);
		int i=0;
		while(i<=max){
			if(x[i]==x[i+1]){
				i+=2;
			}
			else{
				printf("%lld ",x[i]);
				break;
			}
		}
		qsort(y, max, sizeof(long long), cmpfunc);
		i=0;
		while(i<=max){
			if(y[i]==y[i+1]){
				i+=2;
			}
			else{
				printf("%lld\n",y[i]);
				break;
			}
		}
}

	
	return 0;
}
