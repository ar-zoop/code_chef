#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        //exceptions
        if(x==0){
            cout<<"YES";
        }
        //first half
        else
       {    int rem=x%7, rem2=x%2;
            if(rem%2==0){
                cout<<"YES"<<endl;
            }
            else if(rem2%7==0){
                cout<<"YES"<<endl;
                }
            else{
                if((x-7)>0){
                if((x-7)%2==0)
                    cout<<"YES"<<endl;}
                else
                    cout<<"NO"<<endl;
            }
            
          
       }
    }
    return 0;
}