#include <stdio.h>
int main(){
	int t,count_temp, count_else,flag;
	char s[50],temp;
	scanf("%d", &t);
	while(t--){
		scanf("%s",s);
		for (int i=0;s[i]!='\0';i++){
			count_temp=0,count_else=0,flag=0;
			temp=s[i];
			for (int j=0; s[j]!='\0';j++){
				if (temp==s[j])	
					count_temp++;
				else{
					count_else++;
				}
			}
			if (count_temp==count_else){
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("NO\n");
		}
		
	}
	return 0;
}
