#include<stdio.h>
int main(){
	int t,i,j,k,m_count,d_count;
	int n;
	char m[3]="mom", d[3]="dad";
	scanf("%d", &t);
	while(t--){
		m_count=0,d_count=0,j=0,k=0;
		scanf("%d", &n);
		char s[n];		
		scanf("%s", s);
		if(s==" "){
			printf("Goo-Goo\n");
			
		}
		else{
			for (i=0;i<n;i++){
			
				if (s[i]==m[j]){
				printf("--%c--",m[j]);
					m_count++;
//						printf("mom=%d\n",m_count);
					if (m_count==3){
						printf("Mom\n");
						break;
					}
					j++;
				}
				else if(s[i]==d[k]){
					printf("--%c--",d[k]);
					d_count++;
//						printf("dad=%d\n",d_count);
					if (d_count==3){
						printf("Dad\n");
						break;
					}
					k++;
					
				}
			}
			if (m_count!=3 && d_count!=3){
				printf("Goo-Goo\n");
			}
		}
	}
} 
