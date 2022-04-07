#include<stdio.h>

int rectangle(int,int,int,int);

int main(){
	int t, i,a,b,c,d;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (rectangle(a,b,c,d))
			printf("YES");
		else	
			printf("NO");
	}
	return 0;
}

int rectangle(int a, int b, int c, int d){
	
	
	return 0;
}
