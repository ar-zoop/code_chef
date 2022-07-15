#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    
    cin>>n;
    float temp=n;
    int count=0, even_sum=0, odd_sum=0;
    float sum=0;
    while(n!=0){
        int digit=n%10;
        sum+=digit;

        if(digit%2==0){
            even_sum+=digit;
        }
        else{
            odd_sum+=digit;
        }
        n=n/10;
        count++;
    }
    // cout<<count<<" "<<sum<<endl;
    // cout<<"Even sum= "<<even_sum<<" Odd sum= "<<odd_sum;
    if(odd_sum>15){
        // cout<<"discount= "<< n*15/100<<endl;
        temp=temp-(float(temp)*15/100);
        cout<<"15% discount";
    }
    else{
        // cout<<"discount= "<<(float)odd_sum*n/100<<endl;
        temp=temp-(float(odd_sum)*temp/100);      
        cout<<  float(odd_sum)*temp/100<<" discount";
    }
    cout<<endl<<"discounted sum= "<<temp;

    return 0;
}