#include<stdio.h>

int main(){
	int t,n=0,temp,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int a[n];
		int i=0;
		int count=0,count_max=0;
		while(n--){
			scanf("%d", &a[i]);
			if (a[i]%2==0){
				count++;
			}
			else{
				if (count>count_max){
					count_max=count;
					
				}
				count=0;
			}
			i++;
		}
		if (count>count_max){
			count_max=count;
		}
		
	printf("%d\n", count_max);

	
}
return 0;
}

