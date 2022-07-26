#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][4]={0};
    int flag=1;
    //check for upper triangle
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(arr[i][j]==0){
                flag=0;
                break;
            }
            
        }
        if(flag==0) break;
    }
    if(flag==1){
        cout<<"Upper triangle"<<endl;
    }
    //check for lower triangle
    
    else{
        flag=1;
        for(int i=1;i<4;i++){
            for(int j=0;j<i+1;j++){
                if(arr[i][j]==0){
                    flag=0;
                    break;
                }
            }
            if(flag==0) break;
        }
        if(flag==1) cout<<"lower triangle"<<endl;
        else cout<<"neither lwr nor uppr"<<endl;
    }
return 0;
}