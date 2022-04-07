#include <stdio.h>
#include <string.h>
void diff(char[],char[]);

int main(){
	int t, i, a,b;
	char s1[100], s2[100];
	scanf("%d", &t);
	for(i=0;i<t;i++){
		printf("hi\n");
		gets(s1);
		fflush(stdin);
		gets(s2);
		fflush(stdin);
		printf("%s %s\n",s1,s2);
//		printf("hello\n");
		diff(s1,s2);
//		printf("hey\n");
//		b=mbcax(s1,s2);
	}
	return 0;
}

void diff(char s1[],char s2[]){
//	printf("001\n");
	int n=strlen(s1), i;
	printf("%d\n",n);
	int min=n, max=n;
	for (i=0;i<n;i++){
		
		if(s1[i]=='?' || s2[i]=='?')
			min--;
		else if(s1[i]==s2[i]){
			min--;
			max--;
		}		
	}
	printf("%d %d\n",min, max);
}


