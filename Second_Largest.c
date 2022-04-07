#include <stdio.h>
int main(){
	int t,i,a,b,c;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&c);
		if (a>b && a>c){
			if (b>c)	{
				printf("%d",b);
			}
			else {
				printf("%d",c);
			}
		}
		else if (b>a && b>c){
			if (a>c)	{
				printf("%d",a);
			}
			else {
				printf("%d",c);
			}
		}
		else{
			if (b>a)	{
				printf("%d",b);
			}
			else {
				printf("%d",a);
			}
		}
		
	}
	return 0;
}
