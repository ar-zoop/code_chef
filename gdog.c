#include <stdio.h>


int main(){
	int t,k,n,max,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		max= n%1;
		for (i=2;i<k+1;i++){
			if (n%i > max){
				max=n%i;
			}
		}
		printf("%d\n", max);
		
	}
	return 0;
}

