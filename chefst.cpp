#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n1,n2,m;
        cin>>n1>>n2>>m;
        long long max=m*(m+1)/2;
        long long a,b;
        if (n1>n2) { 
          
            b=n2;
        }
        else   { 
           
            b=n1;
        }
        if(max<b){
            n1-=max;
            n2-=max;
        }
        else{
            n1-=b;
            n2-=b;
        }
        cout<<n1+n2<<endl;

    }
    return 0;
}