#include <stdio.h>

int b[100],a[100],c[100],bs[100][2];

int main(void){
	int t,i,j,k,n,temp, tempi;
	scanf("%d", &t);
	for (k=0;k<t;k++){
		scanf("%d",&n);
	
		for (j=0;j<n;j++){
			scanf("%d", &b[j]);
			bs[j][0]=b[j];
		}
		
		for(i=1;i<n;i++){
	      temp=bs[i][0];
	      tempi = i;
	      j=i-1;
	      while((temp<bs[j][0])&&(j>=0)){
	         bs[j+1][0]=bs[j][0];
	         j=j-1;
	      }
	      bs[j+1][0]=temp;
	      bs[j+1][1]=tempi;
   		}
   		
   		for (i=0;i<n;i++){
   			c[bs[i][1]]=i;
		   }
		for (i=0;i<n;i++){
			a[i]=b[i]+c[i];
			
		}
		for (i=0;i<n;i++){
			printf("%d\n", c[i]);
			
		}
		
	} 
	 
	
    return 0;
}
