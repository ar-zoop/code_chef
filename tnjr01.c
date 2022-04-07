#include <stdio.h>

int main(void) {
	// your code goes here
	int n, i, sum,l,j,k;
	char id[8];
	scanf("%d", &n);
	for (i=0;i<n;i++){
	    for (l=0;l<8;l++){
	        scanf("%c", &id[l]);
	    }	      
	   
	    int a=id[7];
	    printf("%d\n",a);
	    
	    int sum=0;
	    if (a%2==0){
	        for ( k=0;k<8;k+=2){
	            sum+=(int)id[k];
	        }
	        
	    }
	    else{
	         for ( k=1;k<8;k+=2){
	            sum+=(int)id[k];
//	            printf("%d\n", sum);
	        }
	    }	   
	  	printf("%d\n",((sum-192)%50)*2);
	 
	}
	return 0;
}


