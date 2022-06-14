#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        // cout<<endl;
        int top;
        int count[n]={0};
        count[n-1]=1;
        for (int i=n-1;i>0;i--){
            top=a[i];
            if (top<0){
                if(a[i-1]>=0) {
                    count[i-1]=count[i]+1;
                    // cout<<"pass 0: "<<count[i-1]<<endl;
                }
                else{
                    count[i-1]=1;
                }
            }
            else{
                if(a[i-1]<0){
                    count[i-1]=count[i]+1;
                    // cout<<"pass 1: "<<count[i-1]<<endl;
                }
                else{
                    count[i-1]=1;
                }
            }
           
        }
        for (int i=0;i<n;i++){
            cout<<count[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 