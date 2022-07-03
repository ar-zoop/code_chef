#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        double sum=0;
        for(int i=k;i<n-k;i++){
            // cout<<arr[i]<<" ";
            sum+=arr[i];
        }
        if(n-k-k>0)
            printf("%lf\n",sum/(n-k-k));
        else
            printf("%f\n",0);
      
    }
    return 0;
}