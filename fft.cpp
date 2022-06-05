#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int p[100001],q[100001];
        long long results[200002]={0};
        for (int i=0;i<n;i++){
            cin>>p[i];
        }
        for (int i=0;i<m;i++){
            cin>>q[i];
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                
                int k=i+j;
                results[k]=results[k]+(p[i]*q[j]);
                
            }
        }
        for(int i=0;i<(n+m-1);i++){
            cout<<results[i]<<" " ;            
        }
        cout<<endl;

    }
    return 0;
}