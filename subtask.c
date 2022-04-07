#include<stdio.h>
int main(){
	int t,n,m,k,i,cases,score,flag;
	scanf("%d", &t);
	while(t--){
		cases=0,score=0,flag=0;
		scanf("%d%d%d",&n,&m,&k);
		int a[n];
		for (i=0;i<n;i++){
			scanf("%d",&a[i]);
			if (a[i]==1){
				cases++;
	
			}
			else if (a[i]==0 && i<m){
				
				flag=1;
			}
		}
//		printf("cases=%d\nscore=%d",cases,score);
		if (cases==n )
			score=100;
		else if (cases>=m && flag==0)
			score=k;
		else
			score=0;
			
		printf("%d\n",score);
	}
}
