#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n!=0){
       
        int arr[n],result[n];
        stack<int> s1, s2;

        for (int i=0;i<n;i++){
            cin>>arr[i];
        }  
              

        
        //push into stack 1 in reverse order
        for(int i=n-1;i>=0;i--){
            s1.push(arr[i]);
        }
        
        
         //sorted array for reference
        sort(arr,arr+n);
       
    
        int data,i=0;
        while(!s1.empty()){
            data=s1.top();
            if(data==arr[i]){
                result[i]=data;
                s1.pop();
                
                i++;
            }
            else if(!s2.empty() && s2.top()==arr[i]){

                result[i]=s2.top();
                s2.pop();
                
                i++;
            }
            else {
                s1.pop();
                s2.push(data);
            }
        }

        while(!s2.empty()){
            result[i]=s2.top();
            s2.pop();
            i++;
        }
        
        int flag=1;
        for(int i=0;i<n;i++){
            if (result[i]!=arr[i])           {flag=0;break;}
        }
        if(flag==0){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
        //if next case exists
        cin>>n;
        
    }
    
    return 0;
}