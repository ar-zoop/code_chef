#include <stdio.h>
#include <string.h>
int res(int);

char s[26];

int main(){
	
	int n,a;
	gets(s);
	scanf("%d",&n);
	while (n--){
	    a=res(n);
	    if(a==1){
		printf("Yes\n");
    	}
    	else{
    		printf("No\n");
    	}
	}
	
	
	return 0;
}

int res(int n){
	int i ,j;
	char w[12];
	gets(w);
	for (i=0;w[i]!='\0';i++){
		for(j=0;j<strlen(s);j++)	{
			if (w[i]!=s[j]){
				return 0;
			}
		}
	}
	return 1;

	
}
