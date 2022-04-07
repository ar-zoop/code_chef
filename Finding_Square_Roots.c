#include <stdio.h>
#include <math.h>
int main(){
	int t,n,i;
	int res;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
		res=sqrt(n);
		printf("%d\n", res);
	}
	
	return 0;
}
