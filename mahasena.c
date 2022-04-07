#include <stdio.h>
int main(){
	int t,n,i,j,flag=1;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		flag=1;
		scanf("%d",&n);
		for (j=2;j<(n/2);j++){
			if (n%j==0){
				flag=0;
				
				
				break;
			}
			else{
				
				;
			}
		}
		if (flag==1){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}
