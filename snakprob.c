#include <stdio.h>
int main(){
	int r,i,l;
	scanf("%d",&r);
	while(r--){
		int flag=0;
		scanf("%d",&l);
		char str[l];
		scanf("%s",str);
		for (i=0;str[i]!='\0';i++){
			if (str[i]=='.')
				continue;
			else if(str[i]=='H'&& flag==0)
				flag=1;
			else if(str[i]=='T' && flag==1)
				flag=0;
			else{
				flag=-99;
				break;
			}
		}
		if (flag==-99||flag==1)
			printf("Invalid\n");
		else
			printf("Valid\n");
			
	}
	return 0;
}
