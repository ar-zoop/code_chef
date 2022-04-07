#include <stdio.h>
#define MAX 1000001
int stack[MAX];
int top=-1;

int main(void){
	int q;
	scanf("%d",&q);
	while(q--){
		int num;
		scanf("%d",&num);
		if(num==1){
			long long n;
			scanf("%lld", &n);
			push(n);
		}
		else{
			pop();
		}
	}
}

void push(long long n){
	stack[++top]=n;
}
void pop(){
	if(top==-1){
		printf("kuchbhi?\n");
	}
	else{
		printf("%d\n",stack[top--]);
	}
}
