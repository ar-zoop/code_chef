#include <stdio.h>

int main(){
	int t, n, k,i;
	scanf("%d", &t);
	while(t--){
		
		scanf("%d %d",&n,&k);
		int arr[n],temp[200001]={0};
		for (i=0;i<n;i++){
			scanf("%d",&arr[i]);
			temp[arr[i]]++;
		}
		for (i=0;i<200001;i++){
			if(temp[i]==0){
				if(k>0){
					k--;
					
				}
				else
					break;
			}
			
		}
		printf("%d\n",i);
	}
	return 0;
}

  
  
