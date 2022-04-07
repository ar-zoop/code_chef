#include <stdio.h>
int main(){
	int i, t,n,max,min;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
		max=n%10;
		
		while(n>0){
			min=n%10;
			n=n/10;
		}
		printf("%d\n",min+max);
	}
	return 0;
}
