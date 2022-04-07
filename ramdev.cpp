#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, b,n, Lh, Bh;
    long long ans=0;
    cin>>l>>b;
    cin>>n;
    while(n--){
        cin>>Lh>>Bh;
        //case 1 :
        int max_l1= Lh/l;
        int max_b1=Bh/b;

        //case 2:
        int max_l2= Lh/b;
        int max_b2=Bh/l;

        //comparision
        ans+= max(max_b1*max_l1 , max_b2*max_l2);
        

    }
    cout<<ans;
    return 0;
}