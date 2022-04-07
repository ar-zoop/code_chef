#include <stdio.h>
#define MAX 100001
int main(){
	long long arr1[MAX]={0},arr2[MAX]={0},s,e;
	int n,m,i,count=0;
	scanf("%d %d",&n,&m);
	while(n--){
		scanf("%lld %lld",&s,&e);
		for (i=s+1;i<=e;i++){
			arr1[i]=1;
		}
	}
	while(m--){
		scanf("%lld %lld",&s,&e);
		for (i=s+1;i<=e;i++){
			arr2[i]=1;
		}
	}
	for(i=0;i<MAX;i++){
		if(arr1[i]==arr2[i] && arr1[i]==1)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
