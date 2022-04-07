#include <stdio.h>
int main(){
	int t,n,i,r,sum;
	scanf ("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		sum=0;
		while(n>0){	
			r=n%10;
			sum+=r;
			n=n/10;
		}
		printf("%d\n",sum);
	}
	return 0;
}
