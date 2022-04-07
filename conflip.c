#include<stdio.h>
#define MAX 2001
void main(){
    int t, j, k;
    int arr[MAX];
    int i,n,q;
    int g, count;
    scanf("%d", &t);
    while(t--){        
        scanf("%d", &g);
        while(g--){            
            scanf("%d%d%d",&i,&n,&q);
            
            for (j=0;j<n;j++){
                arr[j]=i;
            }
            for (j=0;j<n;j++){
                for (k=0;k<=j;k++){
                    if(arr[k]==1){
                        arr[k]=2;
                    }
                    else{
                        arr[k]=1;
                    }
                }
            }
            count=0;
            for (j=0;j<n;j++){
                if(arr[j]==q){
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }
   
}