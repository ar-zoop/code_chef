#include <stdio.h>
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n],b[n],count;
		scanf("%d",&a[0]);
		for (int i=1;i<n;i++){
			scanf("%d",&a[i]);	
			a[i]=a[i]-a[i-1];
		}
		count=0;
		for (int i=0;i<n;i++){
			scanf("%d",&b[i]);
			if (a[i]<=b[i])
				count++;
		}
		printf("%d\n",count);		
	}
	return 0;
}
