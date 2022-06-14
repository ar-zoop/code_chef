#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,k, w[100];
        cin>>n>>k;
        int total_sum=0;
        for (int i=0;i<n;i++){
            cin>>w[i];
            total_sum+=w[i];
        }
        sort(w,w+n);
        int sum1=0;
        for (int i=0;i<k;i++){
            sum1+=w[i];
            
        }
       
        int sum2=0;
        for (int i=n-1;i>=k;i--){
            sum2+=w[i];
            
        }
       cout<<total;
        if (sum1>sum2){
            cout<<total_sum-sum2<<endl;
        }
        else {
            cout<<total_sum-sum1<<endl;
        }
    }

    return 0;
}