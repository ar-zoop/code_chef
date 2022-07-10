#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n], verify[8]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int j=1, i, flag=0;
        for(i=0;i<n;i++){
            if(arr[i]==j){
                verify[arr[i]]++;
            }
            else if(arr[i]==j+1 && verify[j]>0){
                verify[arr[i]]++;
                j++;
            }
            else if(j==7 && arr[i]<j){
                break;
            }
            else{
                if(arr[i]>7||arr[i]<1){
                    flag=1;
                    break;
                }
                else
                    verify[i]=100000000;
            }

        }
        int verify2[8]={0};
        if(flag==1){
            cout<<"no"<<endl;
        }
        
        else{
            for(int k=i;k<n;k++){
                if(arr[k]==j){
                    verify[arr[k]]++;
                }
                else if(arr[k]==j-1 && verify[j]>0){
                    verify[arr[k]]++;
                    j--;
                }
                else{
                    if(arr[k]>7||arr[k]<1){
                        flag=1;
                        break;
                    }
                    verify[k]=100000000;
                }
            }
            flag=0;
            for(int l=0;l<8;l++){
                if((verify[i]-verify2[i])!=0){
                    cout<<"no"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<"yes"<<endl;
            }
        }
       

    }
    return 0;
}