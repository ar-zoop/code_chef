#include <stdio.h>
#define MAX 1000001
void push();
void pop();
int stack1[MAX];
int top1=-1;
int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1];
	for(int i=1;i<n+1;i++){
	    scanf("%d",&a[i]);
	}
	long long fear=1;
	for(int i=n;i>0;i--){
		while(top1!=-1 && a[stack1[top1]]>=a[i]){
			pop();
			// pop(stack2,top2);
		}
        if(top1>-1){
            fear=(fear*(stack1[top1])-i+1)% 1000000007;
            push(i);
        }

	}
	printf("%lld\n",fear);
}

void pop(){
    --top1;
}
void push(int i){
    stack1[++top1]=i;
}