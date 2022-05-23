#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    long long int c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int x;
        long long int sum=0;
        for (int i=0;i<n;i++){
            cin>>x;
            sum+=x;

        }
        
        if(sum<=c) cout<<"Y\n";
        else cout<<"NO\n";
    }
    return 0;

}