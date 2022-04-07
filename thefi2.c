#include <stdio.h>
int main(){
	int t,n,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		char s[n];
		scanf("%s",s);
		if (s==" ")
			printf("Goo-Goo\n");
		else{
			char mom_s[3], dad_s[3];
			int mom_t=-1, dad_t=-1;
			for (i=0;i<n;i++){
				//push mom
				if (s[i]=='m'||s[i]=='o'||s[i]=='m'){
					if (mom_t==-1 && s[i]=='m'){
						mom_t++;
						mom_s[mom_t]=s[i];
					}
					else if (mom_t==0 && s[i]=='o'){
						mom_t++;
						mom_s[mom_t]=s[i];
					}
					else if (mom_t==1 && s[i]=='m'){
						mom_t++;
						mom_s[mom_t]=s[i];
						printf("Mom\n");
						break;
					}
				}
				//push dad
				else if (s[i]=='d'||s[i]=='a'||s[i]=='d'){
					if (dad_t==-1 && s[i]=='d'){
						dad_t++;
						dad_s[dad_t]=s[i];
					}
					else if (dad_t==0 && s[i]=='a'){
						dad_t++;
						dad_s[dad_t]=s[i];
					}
					else if (dad_t==1 && s[i]=='d'){
						dad_t++;
						dad_s[dad_t]=s[i];
						printf("Dad\n");
						break;
					}
				}
			
			}
			
			if (mom_t!=2&&dad_t!=2)
				printf("hello Goo-Goo\n");
		}
	}
	
	

	
}
