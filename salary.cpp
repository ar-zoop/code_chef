#include <bits/stdc++.h>
using namespace std;
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w[100];
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>w[i];
        }
        
        qsort(w, n, sizeof(int), cmpfunc);
        int min=w[0],sum=0;
        for (int i=1;i<n;i++){
            sum+=w[i]-min;
        }
        cout<<sum<<endl;


        
    }
    return 0;
}