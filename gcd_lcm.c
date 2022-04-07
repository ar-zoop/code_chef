#include <stdio.h>
int gcd(int,int);
int lcm(int,int);
int main(){
	int t,a,b,i,c,d;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d", &a,&b);
		c=gcd(a,b);
		d=lcm(a,b);
		printf("%d %d\n",c,d);
	}
	return 0;
}

int gcd(int a, int b){	
	if (b>a){
		return gcd(b,a);
	}

	else if (b==0)
		return a;
	else	
		return gcd(b,a%b);
}

int lcm(int a, int b){
	int c=gcd(a,b);
	return (a/c)*(b/c)*c;

}
