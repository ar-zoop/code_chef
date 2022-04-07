#include <stdio.h>

void digit(int);

int main(){
	int n;
	scanf("%d", &n);
	digit(n);
	return 0;
}

void digit (int n){
	int count=0;
	while (n>0){
		count++;
		n=n/10;
	}
	printf("%d", count);
}
