#include<stdio.h>
#include <string.h>
#define N 100

void min_flip(char []);

int main(){
	int t, i;
	char s[N];
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%d", &s);
		min_flip(s);
	}
	return 0;
}

void min_flip(char s[]){
	int a_count=0, b_count=0;
	int n=len(s),i;
	for (i=0;i<n;i++){
		if(s[i]=='a')
			a_count++;
		else
			b_count++;
	}
	if (a_count>b_count)
		printf("%d", b_count);
	else
		printf("%d", a_count);
}
