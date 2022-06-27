#include <bits/stdc++.h>
using namespace std;
int menu[12];
int expo(int base, int power){
    int a=1;
    for (int i=0;i<power;i++){
        a=a*base;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    for (int i=0;i<12;i++){
        menu[i]=expo(2,i);
    }
    
    while(t--){
        int count=0;
        int p;
        cin>>p;
        // int temp=p;
        int i=11;
        while(i>=0){
            if(p==0){
                cout<<count<<endl;
                break;
            }
            if(menu[i]<=p){
                p-=menu[i];
                count++;
            }
            else{
                i--;
            }
        }
    }
    return 0;
}