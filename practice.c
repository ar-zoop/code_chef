#include <stdio.h>
#include<math.h>

void tricoin(int);

int main(){
	int t,n,i;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%d", &n);
		if (n==0)
			printf("0\n");
		else if (n==1 || n==2)
		    printf("1\n");
	
		else
			tricoin(n);
	}
	
	return 0;
}

void tricoin(int n){
	int a=-(n*2), x, y= (1-(4*a)), z=sqrt(y);
	x=(-1+z)/2;
	printf("%d\n", x);
}
