#include <stdio.h>
int main (){
	int i, count=0, t,n,k;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if (t%k==0){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
