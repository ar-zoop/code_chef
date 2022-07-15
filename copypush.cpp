#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int flag=0;
         while(!s.empty()){
            while(s.length()%2==0){
                string firstHalf,secondHalf;
                for(int i=0;i<s.length();i++){
                    if(i<(s.length()/2))
                        firstHalf+=s[i];
                    else
                        secondHalf+=s[i];
                }
                if(firstHalf==secondHalf){
                    s=firstHalf;
                }
                else{
                    flag=-1;
                    break;
                }
            }
            if(flag==-1) break;
            if(s.length()%2!=0){
                s.pop_back();
            }
        }
        if(flag==-1) cout<<"NO"<<endl;
        else if(s.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}