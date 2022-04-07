#include<stdio.h>
int main(){
    int n,flag;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++){
        flag=0;
        for (int j=i;j<n;j++){
            if (arr[i]<arr[j]){
                printf("%d ",arr[j]);
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("-1 ");
        }
    }
    return 0;
}