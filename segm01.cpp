#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flag=1000;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1' && flag==1000) flag=1;
            else if (s[i]=='0' && flag==1) flag=0;
            else if(s[i]=='1' && flag==0) {
                cout<<"NO"<<endl;
                flag=-1;
                break;
            }
        }
        if(flag!=-1 && flag!=1000) cout<<"YES"<<endl;
        else if(flag==1000) cout<<"NO"<<endl;
        
    }
    return 0;
}