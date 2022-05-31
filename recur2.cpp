//print number n times using recursion
#include <bits/stdc++.h>
using namespace std;

void recur(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    recur(i+1,n);
}

void recur2(int n){
    if(n==0) return;
    cout<<n<<endl;
    recur2(n-1);
}

int main(){
    recur(1,5);
    cout<<endl;
    recur2(6);
    return 0;
}