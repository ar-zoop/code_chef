//print name n times using recursion
#include <bits/stdc++.h>
using namespace std;

string name="arzoo";

void recur(int n){
    if(n==0) return;
    cout<<name<<endl;
    recur(n-1);
}

int main(){
    recur(5);
    return 0;
}