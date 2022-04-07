#include <stdio.h>
#include <string.h>
int compare(char[], char[]);

int main(){
	int t,i,res;
	char x[10], y[10];
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%s%s",x,y);
		res=compare(x,y);
		if (res==1)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
	return 0;
}

int compare(char x[], char y[]){
	int n=strlen(x), i;
	for (i=0;i<n;i++){
		if (x[i]!=y[i] && x[i]!='?' && y[i]!='?')
			return 0;
	}
	return 1;
}
