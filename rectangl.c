#include <stdio.h>

int is_rectangle(int,int,int,int);
int main(){
	int t, i, a, b, c, d, res;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		res= is_rectangle(a,b,c,d);
		if (res==1)
			printf("YES");
		else
			printf("NO");
	}
	return 0;
}

int is_rectangle(int a, int b, int c, int d){
	if (a==b && c==d)
		return 1;
	else if (a==c && b==d)
		return 1;
	else if(a==d && b==c)
		return 1;
	return 0;
}
