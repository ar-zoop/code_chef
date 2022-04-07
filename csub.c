#include <stdio.h>
int main(){
	int t,n,i,j;
	scanf("%d", &t);
	while(t--)
	{
		
		int count=0;
		scanf("%d", &n);
		char a[n];
		scanf("%s", a);
		for (i=0;i<n;i++){
			if(a[i]=='1')
				count++;
				
			}
				
				printf("%d\n", (count*(count+1))/2);
			}
				return 0;
		}
		
	
