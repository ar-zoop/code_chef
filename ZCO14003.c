#include <stdio.h>
int cmpfunc(const void *a, const void *b){
    return (*(int *)a-*(int *)b);
}
int main(){
    int n;
    scanf("%d", &n);
    long long b[n];
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    qsort(b,n,sizeof(long long),cmpfunc);
    int max=0,temp;
    for (int i=n;i>0;i--){
        temp=b[n-i-1]*n;
        if(temp>max){
            max=temp;
        }
    }
    printf("%d\n",max);
    return 0;
}