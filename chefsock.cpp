#include <bits/stdc++.h>
using namespace std;

int main(){
    int jacketCost, sockCost, money;
    cin>>jacketCost>> sockCost>> money;
    int remainingMoney= money- jacketCost;
    if(remainingMoney>=sockCost){
        int numberOfSocks=remainingMoney/sockCost;
        if(numberOfSocks%2==0){
            cout<<"Lucky Chef"<<endl;
        }
        else{
            cout<<"Unlucky Chef"<<endl;
        }
    }
    else{
        cout<<"Unlucky Chef"<<endl;
    }
    return 0;
}