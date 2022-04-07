#include <stdio.h>

int alter(int [], int, int);

int main(){
    int t,n, sum, sum2, i,j;
    scanf("%d", &t);
    for (i=0; i<t; i++){
        scanf("%d", &n);
        int a[n];
        
        for (j=0;j<n;j++){
            scanf("%d", &a[j]);
        }
        
        sum=alter(a,0 ,n);
        sum2=alter(a,1, n);
        if(sum>sum2 ){
            printf("%d\n", sum);
		}
        else {
            printf("%d\n", sum2);
		}     
        
        
            
    }
    return 0;
}

int alter(int a[], int seq, int n){
    int sum=0, i;
    for (i=seq;i<n;i+=2){
        sum+=a[i];
    }
    return sum;
    
}
