#include <stdio.h>
int main(){
	int max,a,b,t,i;
	scanf("%d",&t);	
	for (i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		if (a>b){
			max=a+b;
			printf("%d %d\n",a,max);
		}
		else if (a<b){
			max=a+b;
			printf("%d %d\n",b,max);
		}
	}

	return 0;
}
