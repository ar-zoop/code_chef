#include <stdio.h>
int main(){
	
	int i,n,t;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		if (n<10){
			
			printf("Thanks for helping Chef!\n");
			
		}
		else{
			printf("-1\n");
		}
	}
	
	return 0;
}
