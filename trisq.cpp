#include <bits/stdc++.h>
using namespace std;
int trisq(int b){
    if(b/2==1 || b/2==0) return 0;
    return ((b/2)-1)+trisq(b-2);

}

int main(){
    int t;
    cin>>t;
    while(t--) {
        int b,res;
        cin>>b;
        res=trisq(b);
        cout<<res<<endl;
    }
    return 0;
}