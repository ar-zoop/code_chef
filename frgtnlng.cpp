#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
    int t,n,k,l;
    string word;
    map <string,int>mod_dict;
    cin>>t;
    while(t--){
        cin>>n>>k;
        char dict[100][5];
        for (int i=0;i<n;i++){
            cin>>dict[i];
        }
      
        for (int i=0;i<k;i++){
            cin>>l;
            while(l--){                
                cin>>word;
                mod_dict[word]++;
            }
        }
        for (int i=0;i<n;i++){
           cout<<dict[i]<<endl;
            if(mod_dict[dict[i]]>=1){
                cout<<"YES ";
            }
            else{
                cout<<"NO ";
            }  
            
        }
        cout<<endl;

    }
    return 0;
}