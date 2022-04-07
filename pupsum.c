#include <stdio.h>


int sum(int);

int main(){
	int t, i, d, n, j,s;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%d%d", &d,&s);
		for (j=0;j<d;j++){
			s=sum(s);
		}
		printf("%d\n", s);
	}
	return 0;
}

int sum(num){
	int i,n=0;
	for(i=1;i<=num;i++){
			n+=i;
	}
	return n;
	
}
