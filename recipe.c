#include <stdio.h>
int arr[50],n;
int gcd(int,int);
int gcd1();
int main(){
	int t,n,q,i,j,a;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		a=gcd1();
		
		for (j=0;j<n;j++){
		    printf("%d ",arr[j] );
		    printf("%d ",arr[j]/a);
		}
	}
	return 0;
}

int gcd1(){	
	int a,b,j;
	scanf("%d",&n);
	scanf("%d",&a);
	arr[0]=a;
	printf("%d",arr[0]);
	for (j=1;j<n;j++){
		scanf("%d",&b);
		arr[j]=b;
		a=gcd(a,b);
	}
	printf();
	return a;
	
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
