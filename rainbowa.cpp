#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        stack <int> stk;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int check=1, flag=0, i;
        for(i=0;i<n;i++){
            if(check==arr[i] && check!=7){
                stk.push(arr[i]);
            }
            else if((check+1)==arr[i] && check!=7){
                int x=stk.top();
                if(arr[i]==7){
                    check++;
                }
                else if(x==check){
                    stk.push(arr[i]);
                    check++;
                }
                else{
                    // stk.push(x);
                    flag=1;
                    break;
                }
            }
            else if(check==7 && arr[i]<check){
                break;
            }
            else if (arr[i]>7){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"no"<<endl;
            // cout<<"pass -1";
        }
        else{
            // check=6;
            for(int j=i;j<n;j++){
                if(!stk.empty()){
                    if(arr[j]==(stk.top())){
                        stk.pop();
                    }
                }
                else{
                    flag=1;
                    break;
                }
            }
            
            if(flag==1){
                cout<<"no"<<endl;
                // cout<<"pass 0";
            }
            
            else{
                if(!stk.empty()){
                    cout<<"no"<<endl;
                    // cout<<"pass 1";
                }
                else{
                    cout<<"yes"<<endl;
                    // cout<<"pass 2";
                }
            }
        }
          
    }
    return 0;
}