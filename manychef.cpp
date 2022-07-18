#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n;
        n=s.length();
        for(int i=n-1;i>=0;i--){
            if((s[i]=='?' || s[i]=='F') && (i-3>=0)){
                if(s[i-1]=='?' || s[i-1]=='E'){
                    if(s[i-2]=='?' || s[i-1]=='H'){
                        if(s[i-3]=='?' || s[i-1]=='C'){
                            s[i]=='F';s[i-1]=='E';s[i-1]=='H';s[i-1]=='C';
                            i-=3;
                        }
                    }                    
                }               
            }
            else{
                continue;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]=='A';
            }
        }
        cout<<s;
    }
    return 0;
}