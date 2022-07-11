#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2,m;
        cin>>n1>>n2>>m;
        int max=m*(m+1)/2;
        if(max<=min(n1,n2)){
            n1-=max;
            n2-=max;

        }
        else if(n1<=m && n2<=m){
            int mini=min(n1,n2);
            n1-=mini;
            n2-=mini;
        }
        
        else if(n1<=m || n2<=m){
            int mini=min(n1,n2);
            n1-=mini;
            n2-=mini;
        }
        else{
            int mini=min(n1,n2);
            n1-=mini;
            n2-=mini;
        }
       cout<<n1+n2<<endl;
    }
    return 0;
}