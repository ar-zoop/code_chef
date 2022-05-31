#include <bits/stdc++.h>
using namespace std;

//print for 1 to n but use backtracking
void backtracking(int n){
    if(n==0) return;
    backtracking(n-1);
    cout<<n;
}

//print for 1 to n but use backtracking
void bt(int i, int n){
    if(i>n)return;
    bt(i+1,n);
    cout<<i;
}

int main(){
    backtracking(5);
    cout<<endl;
    bt(1,7);
    return 0;
}