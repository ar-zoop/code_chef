#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[100000],highscore[100000];
        int max=0,ques;
        for (int i=0;i<n;i++){
            cin>>a[i];
            if(max<a[i]){
                max=a[i];
            }
            highscore[i]=max;

        }
        for (int i=0;i<q;i++){
            cin>>ques;
            cout<<highscore[ques-1]<<endl;
        }
    }
    return 0;
}