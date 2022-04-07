#include<stdio.h>
int main(){
	int t,n,i, j,layers;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		layers=0;
		j=1;
		scanf("%d", &n);
		n=n-j;
		while(n>0){
			
			j++;
			layers++;
			n=n-j;
		}
		printf("%d\n", layers);
	}
	return 0;
}
