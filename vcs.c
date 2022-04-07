#include <stdio.h>
int dequeue(int[],int,int);int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int a[100],b[100],fa=0,fb=0,fog=0,original[100],ra,rb,rog;

        int n,max,m,k,igtrack=0;;
        scanf("%d%d%d",&n,&m,&k);
        ra=m;
        rb=k;
        rog=n;
        for (int i=0;i<n;i++){
            original[i]=i+1;
        }
        for (int i=0;i<m;i++){
            scanf("%d", &a[i]);
        }
        for (int i=0;i<k;i++){
            scanf("%d", &b[i]);
        }

        while(fa!=ra && fb!=rb){
            if(a[fa]==b[fb]){
                fa=dequeue(a,fa,ra);
                fb=dequeue(b,fb,rb);
                fog=dequeue(original,fog,rog);
                igtrack++;
            }
            else if(a[fa]>b[fb]){
                fb=dequeue(b,fb,rb);
                fog=dequeue(original,fog,rog);
            }
            else{                
                fa=dequeue(a,fa,ra);
                fog=dequeue(original,fog,rog);
            }
        }
        
        printf("%d %d\n",igtrack,n-fog);
    }
    return 0;
}
int dequeue(int queue[],int f,int r){
    if(f>=r){
        return r;
    }
    return f++;
}