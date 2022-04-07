#include <stdio.h>
int main(){
	int t,n,i,r,sum;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
//		reversing code
		sum=0;
		while(n>=0){
			r=n%10;
			sum=(sum*10)+r;
			n=n/10;
			
		}
		printf("%d",sum);
	}
	
	return 0;
}
