#include <bits/stdc++.h>
using namespace std;

void prime(){
    int sum=0,count=0;
    cout<<"list of prime numbers: ";
    for(int i=100;i<201;i++){
        int flag=0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<i<<" ";
            sum+=i;
            count++;
        }
    }
    cout<<endl<<"sum of all prime numbers from 100-200 = "<<sum<<endl;
    cout<<"count= "<<count<<endl;
    return ;
}

void fact(int lwr, int upr){
    int prod=1, count=0;
    for(int i=1;i<upr+1;i++){
        prod=prod*i;
        if(prod>=lwr && prod<=upr){
            count++;
        }
    }
    cout<<"number of factorials found between "<<lwr<<" and "<<upr<<"="<<count<<endl;
    return ;
}

void number_to_word(int num){
    //2 digits
    if(num>10 && num < 20){
        int teens=num;
        switch(teens){
            case 11:
                cout<<"eleven"<<endl;
                break;
            case 12:
                cout<<"twelve"<<endl;
                break;
            default:
                cout<<"kuch aur dalo";
        }
    }
    else{
        int tens=num/10;
        switch(tens){
            case 2:
                cout<<"twenty ";
                break;
            case 3:
                cout<<"thirty ";
                break;
        }
        int ones=num%10;
        switch(ones){
            case 1:
                cout<<"one"<<endl;
                break;
            case 2:
                cout<<"two"<<endl;
                break;
        }
    }
    return;
    
}

int main(){
    prime();
    fact(10,30);
    int num;
    cin>>num;
    while(true){
        number_to_word(num);
        cin>>num;
    }
    return 0;
}