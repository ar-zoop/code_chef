#include <stdio.h>
#include <string.h>

void diff(char[],char[]);

int main(){
	int t, i, a,b;
	char s1[100], s2[100];
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%s%s",s1,s2);
		diff(s1,s2);
	}
	return 0;
}

void diff(char s1[],char s2[]){
	int n=strlen(s1), i;
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


