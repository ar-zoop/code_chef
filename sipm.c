#include <stdio.h>
int cmp(void const *a, void const *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        long long sum_pos=0, sum_neg=0;
        scanf("%d",&n);
        int arr[n];
        for (int i=0;i<n;i++){

            scanf("%d", &arr[i]);
            
        }
        qsort(arr,n,sizeof(int),cmp);
        int cur=arr[0];
        if(cur>0){
            sum_pos+=cur;
        }
        else{
            sum_neg+=cur;
        }
        for (int i=1;i<n;i++){
          if(arr[i]!=cur){
                if (arr[i]>0){
                    cur=arr[i];
                    sum_pos+=arr[i];
                }
                else if(arr[i]<0){
                    cur=arr[i];
                    sum_neg+=arr[i];
                }
           }
        }

        printf("%lld %lld\n",sum_pos,sum_neg);
    }
    return 0;
}