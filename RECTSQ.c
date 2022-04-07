#include <stdio.h>
int gcd(int,int);
int main(){int t;
	scanf("%d",&t);
	while(t--){
		int n,m,res,a,b;
		scanf("%d%d",&n,&m);
		res=gcd(n,m);
		a=n/res;
		b=m/res;
		printf("%d\n",a*b);
	}
	return 0;
}
int gcd(int a, int b){	
	if (b>a)
		return gcd(b,a);
	else if (b==0)
		return a;
	else	
		return gcd(b,a%b);
}
