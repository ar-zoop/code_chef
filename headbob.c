#include <stdio.h>

int check(char[]);

int main(){
	int t,n,i,a;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
		char s[n];
		scanf("%s", &s);
		a=check(s);
		if (a==1)
			printf("INDIAN");
		else if(a==0)
			printf("NOT INDIAN");
		else
			printf("NOT SURE");
	}
	return 0;
}

int check(char s[]){
	int res=-99,i=0;
	while (s[i]!='\0'){
		if (s[i]=='I'||s[i]=='i')
			return 1;
		else if(s[i]=='Y' || s[i]=='y')
			res=0;
		i++;	
	}
	return res;
	
}
