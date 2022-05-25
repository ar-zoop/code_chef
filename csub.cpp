#include <bits/stdc++.h>
using namespace std;
#define N 100000
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,count=0;
        cin>>n;
        int s[N];
        cin>>s;
        for (int i =0;i<n;i++){
            if(s[i]==1){
                count++;
                for (int j=i;j<n;j++){
                    if(s[j]==1){
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}
