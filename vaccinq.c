#include<stdio.h>
int main(){
	int t, n,p,x,y,timee;
	scanf("%d", &t);
	while(t--){		
	
		scanf("%d %d %d %d",&n,&p,&x,&y);
//		printf("y=%d\n",y);
			timee=0;
		int a[n], i=0;		
		while(n--){
			scanf("%d", &a[i]);
			if (a[i]==0 && i<p){
				timee+=x;
			}
			else if (a[i]==1 && i<p){
				timee+=y;
			
			}
			i++;
		}
		printf("%d\n",timee);
	}
return 0;
}

