#include <iostream>
using namespace std;

int F[51];
int fib(int n){
    if(n<=1)return n;
    if (F[n]!=-1) return F[n];
    F[n]= fib(n-1)+fib(n-2);
    return F[n];
}

int main(){
    int n=40, result;
    for (int i=0;i<51;i++){
        F[i]=-1;
    }
    result=fib(n);
    cout<<result<<endl;
    return 0;
}