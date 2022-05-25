#include <bits/stdc++.h>
using namespace std;
int main(){
   
    
    int t;
    cin>>t;
   
    while(t--){
        char s[1001];
        int count[26]={0},n;
        cin>>s;
        for (int i=0;i<strlen(s)/2;i++){
           count[int(s[i])-97]++;             
        }
        n=strlen(s)/2;
        if(strlen(s)%2!=0){
            n=(strlen(s)/2)+1;
        }
        
        for (int i=n;i<strlen(s);i++){
             count[int(s[i])-97]--; 
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"YES"<<endl;
    }
    return 0;
    
}