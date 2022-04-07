#include <stdio.h>
int main(){
	int t,n,i,cost,min;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int a[n];
		for (i=0;i<n;i++)
			scanf("%d", &a[i]);
			
		if (a[0]>a[1]){
			min=a[1];
			
		}
		else{
			min=a[0];
		}
		cost=min;
		for (i=2;i<n;i++){
			if (a[i]>min){
				cost+=min;
			}
			else {
				min=a[i];
				cost+=a[i];
			}
		}
		printf("%d\n",cost);
	}
	return 0;
}
