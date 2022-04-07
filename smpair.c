#include <stdio.h>
#define NOTNULL 'a'
int main(){
	int t,n,i,j=0;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%d", &n);
		int a[n],small=NOTNULL,big=NOTNULL;
		scanf("%d",&a[j]);
//		small=a[j];
//		printf("%d ",small);
		for (j=1;j<n;j++){
			scanf("%d",&a[j]);
			if(a[j]<=small){
				big=small;
				small=a[j];
				printf("%d %d ",small,big);
			}
			if(a[j]<=small && ){
				big=small;
				small=a[j];
				printf("%d %d ",small,big);
			}
		}
		printf("%d\n",big+small);
	}
	return 0;
}
