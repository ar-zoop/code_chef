#include <bits/stdc++.h>
using namespace std;

void fun(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    for(int j=0;j<10;j++){
        
        fun(i*10+j,n);
    }
    
}

int main(){
    int n=1000;
    for(int i=1;i<=9;i++){
        fun(i,n);
    }
    return 0;
}